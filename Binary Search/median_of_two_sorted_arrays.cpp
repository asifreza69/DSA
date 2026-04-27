#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int l = 0, h = m;

        while (l <= h) {
            int lx = l + (h - l) / 2;
            int rx = (m + n + 1) / 2 - lx;

            int x1 = (lx == 0) ? INT_MIN : nums1[lx - 1];
            int x2 = (rx == 0) ? INT_MIN : nums2[rx - 1];
            int x3 = (lx == m) ? INT_MAX : nums1[lx];
            int x4 = (rx == n) ? INT_MAX : nums2[rx];

            if (x1 <= x4 && x2 <= x3) {
                if ((m + n) % 2 == 1) {
                    return max(x1, x2);
                } else {
                    return (max(x1, x2) + min(x3, x4)) / 2.0;
                }
            }

            else if (x1 > x4) {
                h = lx - 1;
            } else {
                l = lx + 1;
            }
        }

        return -1;
    }
};

/*
Approach (Partition Binary Search):

1. Always binary search on smaller array

2. Partition arrays such that:
   left part size = right part size

3. Conditions:
   x1 <= x4 AND x2 <= x3

4. Median:
   Odd → max(left)
   Even → avg(max(left), min(right))

Time Complexity: O(log(min(m,n)))
Space Complexity: O(1)
*/

#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;        // last valid element in nums1
        int j = n - 1;        // last element in nums2
        int k = m + n - 1;    // last index of nums1

        // Merge from end
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // If nums2 still has elements
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};

/*
Problem: Merge Sorted Array (LeetCode 88)

Approach:
Two-pointer from the end (in-place merge)

Logic:
- Compare last elements of both arrays
- Place larger element at end of nums1
- Move pointers accordingly

Time Complexity:
O(m + n)

Space Complexity:
O(1)

Key Insight:
Filling from the end avoids overwriting elements in nums1
*/

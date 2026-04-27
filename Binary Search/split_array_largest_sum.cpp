#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    bool ispossible(int mid, vector<int>& nums, int k) {
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if (sum > mid) {
                sum = nums[i];
                k--; // one split used
            }
        }

        return k >= 0;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = low;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // pass k-1 because first subarray already exists
            if (ispossible(mid, nums, k - 1)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};

/*
Approach (Your Logic):

1. Binary Search on Answer:
   - low = max element
   - high = total sum

2. mid = maximum allowed subarray sum

3. Greedy Check:
   - Keep adding elements
   - If sum > mid → create new subarray
   - Decrease k (splits)

4. k-1 Logic:
   - Already 1 subarray exists
   - So only k-1 splits allowed

5. If k < 0 → not possible

Time Complexity: O(n log(sum))
Space Complexity: O(1)
*/

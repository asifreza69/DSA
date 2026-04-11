#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return;

        k = k % n;

        // Step 1: Reverse entire array
        reverse(nums.begin(), nums.end());

        // Step 2: Reverse first k elements
        reverse(nums.begin(), nums.begin() + k);

        // Step 3: Reverse remaining elements
        reverse(nums.begin() + k, nums.end());
    }
};

/*
Problem: Rotate Array (LeetCode 189)

Approach:
Reversal Algorithm

Logic:
- Reverse whole array
- Reverse first k elements
- Reverse remaining n-k elements

Example:
[1,2,3,4,5,6,7], k=3
→ [7,6,5,4,3,2,1]
→ [5,6,7,4,3,2,1]
→ [5,6,7,1,2,3,4]

Time Complexity:
O(n)

Space Complexity:
O(1)

Key Insight:
Reversal preserves order while rotating efficiently
*/

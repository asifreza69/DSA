/*
Problem: Product of Array Except Self (LeetCode 238)

Approach:
Used prefix and suffix product technique without division.

Logic:
1. First pass:
   - Store prefix product in ans array
   - ans[i] = product of all elements before i

2. Second pass (reverse):
   - Maintain suffix product in variable t
   - Multiply ans[i] with suffix product

Time Complexity: O(n)
Space Complexity: O(1) (excluding output array)

Key Insight:
Each element = (prefix product) * (suffix product)
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        
        // Step 1: Prefix product
        ans.push_back(1);
        for (int i = 1; i < nums.size(); i++) {
            int t = ans[i - 1] * nums[i - 1];
            ans.push_back(t);
        }

        // Step 2: Suffix product
        int t = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--) {
            ans[i] = ans[i] * t;
            t = t * nums[i];
        }

        return ans;
    }
};



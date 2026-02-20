// LeetCode 1911: Maximum Alternating Subsequence Sum
//
// Approach: Dynamic Programming + Memoization
//
// Idea:
// - We choose a subsequence such that:
//      even index elements are added
//      odd index elements are subtracted
//
// - At each index we have two choices:
//      1. Take the current element
//      2. Skip the current element
//
// - DP State:
//      dp[i][flag]
//      flag = true  -> next operation is addition
//      flag = false -> next operation is subtraction
//
// - Recurrence:
//      take = value(with sign) + solve(i+1, !flag)
//      skip = solve(i+1, flag)
//      dp[i][flag] = max(take, skip)
//
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    long long t[1000001][2]; // Memo table: index vs add/subtract state

    // Recursive function with memoization
    long long solve(int i, vector<int>& nums, bool flag) {
        // Base case: reached end of array
        if (i >= nums.size()) {
            return 0;
        }

        // Return cached result if already computed
        if (t[i][flag] != -1) {
            return t[i][flag];
        }

        // Option 1: Skip current element
        long long skip = solve(i + 1, nums, flag);

        // Option 2: Take current element
        long long val = nums[i];

        // If flag is false, subtract instead of add
        if (flag == false) {
            val = -val;
        }

        // After taking, flip the flag (add <-> subtract)
        long long take = val + solve(i + 1, nums, !flag);

        // Store and return the best choice
        return t[i][flag] = max(take, skip);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        // Initialize memo table with -1
        memset(t, -1, sizeof(t));

        // Start from index 0 with addition state
        return solve(0, nums, true);
    }
};

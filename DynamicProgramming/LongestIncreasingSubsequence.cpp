// LeetCode 300: Longest Increasing Subsequence
//
// Approach: Top-Down Dynamic Programming (Memoization)
//
// Idea:
// - At each index we decide whether to:
//      1. Take the element (if increasing)
//      2. Skip the element
//
// - DP State:
//      solve(prev_index, current_index)
//
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)

class Solution {
public:
    int n;
    int dp[2501][2501];

    int solve(int prev, int curr, vector<int>& nums) {
        if (curr == n) {
            return 0;
        }

        if (prev != -1 && dp[prev][curr] != -1) {
            return dp[prev][curr];
        }

        // Option 1: Skip current element
        int skip = solve(prev, curr + 1, nums);

        // Option 2: Take current element (if valid)
        int take = 0;
        if (prev == -1 || nums[curr] > nums[prev]) {
            take = 1 + solve(curr, curr + 1, nums);
        }

        if (prev != -1)
            dp[prev][curr] = max(take, skip);

        return max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(-1, 0, nums);
    }
};





// Approach: Bottom-Up Dynamic Programming
//
// Idea:
// - For each index i, find the length of the longest increasing
//   subsequence ending at i.
//
// - Let dp[i] = length of LIS ending at index i
//
// - For every i, check all j < i:
//      if nums[i] > nums[j]
//          dp[i] = max(dp[i], dp[j] + 1)
//
// - Final answer = maximum value in dp array
//
// Time Complexity: O(n^2)
// Space Complexity: O(n)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        // Edge case
        if (n == 0) return 0;

        // dp[i] = LIS ending at index i
        vector<int> t(n, 1);

        int maxi = 1;  // Stores overall maximum LIS length

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // If current element can extend increasing subsequence
                if (nums[i] > nums[j]) {
                    t[i] = max(t[i], t[j] + 1);
                }
            }
            // Update global maximum
            maxi = max(maxi, t[i]);
        }

        return maxi;
    }
};




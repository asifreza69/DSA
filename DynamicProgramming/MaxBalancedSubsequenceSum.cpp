// LeetCode 2926: Maximum Balanced Subsequence Sum
//
// Approach: Top-Down Dynamic Programming + Memoization (using HashMap)
//
// Idea:
// - We want to choose a subsequence such that:
//      nums[i] - i >= nums[p] - p
//   where p is previous chosen index.
//
// - At each index we have two choices:
//      1. Take the current element (if valid)
//      2. Skip the current element
//
// - DP State:
//      solve(prev_index, current_index)
//
// - Use unordered_map<string, long long> for memoization
//
// Time Complexity: O(n^2) in worst case
// Space Complexity: O(n^2)

class Solution {
public:
    int n;
    unordered_map<string, long long> mp;  // Memoization map

    long long solve(int prev, int curr, vector<int>& nums) {

        // Base case
        if (curr >= n) {
            return 0;
        }

        // Create unique key for state
        string key = to_string(prev) + "_" + to_string(curr);

        // If already computed
        if (mp.find(key) != mp.end()) {
            return mp[key];
        }

        long long take = 0;

        // Take current element if valid
        if (prev == -1 || nums[curr] - curr >= nums[prev] - prev) {
            take = nums[curr] + solve(curr, curr + 1, nums);
        }

        // Skip current element
        long long skip = solve(prev, curr + 1, nums);

        // Store and return best result
        return mp[key] = max(take, skip);
    }

    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        n = nums.size();

        // Edge case: if all elements are negative
        long long maxi = *max_element(nums.begin(), nums.end());
        if (maxi <= 0) {
            return maxi;
        }

        return solve(-1, 0, nums);
    }
};

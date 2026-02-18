class Solution {
public:
    int t[101];  // Memoization array to store results of subproblems

    // Recursive function to calculate maximum money starting from index i
    int solve(int i, vector<int>& nums) {
        // Base case: If index goes beyond array size, no money can be robbed
        if (i >= nums.size()) {
            return 0;
        }

        // If result already computed, return stored value
        if (t[i] != -1) {
            return t[i];
        }

        // Option 1: Rob current house and skip next house
        int take = nums[i] + solve(i + 2, nums);

        // Option 2: Skip current house
        int skip = solve(i + 1, nums);

        // Store and return the maximum of both choices
        return t[i] = max(take, skip);
    }

    int rob(vector<int>& nums) {
        // Initialize memoization array with -1
        memset(t, -1, sizeof(t));

        // Start recursion from index 0
        return solve(0, nums);
    }
};

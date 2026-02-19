class Solution {
public:
    
    // Recursive function with memoization
    // i = current index
    // n = last valid index
    int solve(int i, int n, vector<int>& nums, vector<int>& t) {
        
        // Base case: if index goes beyond allowed range
        if (i > n) {
            return 0;
        }

        // If already computed, return stored value
        if (t[i] != -1) {
            return t[i];
        }

        // Option 1: Rob current house and skip next
        int take = nums[i] + solve(i + 2, n, nums, t);

        // Option 2: Skip current house
        int skip = solve(i + 1, n, nums, t);

        // Store and return maximum
        return t[i] = max(take, skip);
    }

    int rob(vector<int>& nums) {
        
        // Edge case: only one house
        if (nums.size() == 1) {
            return nums[0];
        }

        // Edge case: two houses
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }

        int n = nums.size() - 1;

        // Case 1: Rob houses from index 0 to n-1 (exclude last house)
        vector<int> t(n + 1, -1);
        int ans1 = solve(0, n - 1, nums, t);

        // Case 2: Rob houses from index 1 to n (exclude first house)
        t.assign(n + 1, -1);
        int ans2 = solve(1, n, nums, t);

        // Return maximum of both cases
        return max(ans1, ans2);
    }
};

// LeetCode 368: Largest Divisible Subset
//
// Approach: Bottom-Up Dynamic Programming
//
// Idea:
// - First sort the array.
// - For each index i, find the largest divisible subset ending at i.
//
// - dp[i] = size of largest divisible subset ending at index i
// - parent[i] = previous index in the subset (to reconstruct answer)
//
// - For every i, check all j < i:
//      if nums[i] % nums[j] == 0
//          dp[i] = max(dp[i], dp[j] + 1)
//
// - Track the index where maximum subset size occurs.
// - Reconstruct subset using parent array.
//
// Time Complexity: O(n^2)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n = nums.size();

        // Edge case
        if (n == 1) {
            return {nums[0]};
        }

        // Sort to ensure divisible chain works properly
        sort(nums.begin(), nums.end());

        vector<int> count(n, 1);   // dp array
        vector<int> index(n, -1);  // parent tracking

        int maxi = 1;
        int startindex = 0;

        // Build DP
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {

                // If divisible, try extending subset
                if (nums[i] % nums[j] == 0) {

                    if (count[i] < count[j] + 1) {
                        count[i] = count[j] + 1;
                        index[i] = j;
                    }

                    // Track maximum subset length
                    if (count[i] > maxi) {
                        maxi = count[i];
                        startindex = i;
                    }
                }
            }
        }

        // Reconstruct answer
        vector<int> ans;
        while (startindex != -1) {
            ans.push_back(nums[startindex]);
            startindex = index[startindex];
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

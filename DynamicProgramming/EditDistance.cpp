// LeetCode 72: Edit Distance
//
// Approach 1: Top-Down Dynamic Programming (Memoization)
// Approach 2: Bottom-Up Dynamic Programming (Tabulation)
//
// Idea:
// - We need minimum operations to convert word1 → word2.
// - Allowed operations:
//      1. Insert
//      2. Delete
//      3. Replace
//
// Recurrence:
// - If characters match:
//      dp[i][j] = dp[i-1][j-1]
// - Else:
//      dp[i][j] = 1 + min(
//                      dp[i-1][j],     // Delete
//                      dp[i][j-1],     // Insert
//                      dp[i-1][j-1]    // Replace
//                  )

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

class Solution {
public:
    int memo[501][501];

    // ----------- Top-Down (Memoization) -----------
    int solve(int i, int j, string& w1, string& w2) {

        if (i == 0) return j;
        if (j == 0) return i;

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        if (w1[i - 1] == w2[j - 1]) {
            return memo[i][j] = solve(i - 1, j - 1, w1, w2);
        }

        int insertOp  = 1 + solve(i, j - 1, w1, w2);
        int deleteOp  = 1 + solve(i - 1, j, w1, w2);
        int replaceOp = 1 + solve(i - 1, j - 1, w1, w2);

        return memo[i][j] = min(insertOp, min(deleteOp, replaceOp));
    }

    int minDistance(string w1, string w2) {

        int m = w1.size();
        int n = w2.size();

        // Uncomment below for Top-Down version
        /*
        memset(memo, -1, sizeof(memo));
        return solve(m, n, w1, w2);
        */

        // ----------- Bottom-Up (Tabulation) -----------

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {

                if (i == 0 || j == 0) {
                    dp[i][j] = i + j;
                }
                else if (w1[i - 1] == w2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = 1 + min(
                        dp[i - 1][j],      // Delete
                        min(dp[i][j - 1],  // Insert
                            dp[i - 1][j - 1]) // Replace
                    );
                }
            }
        }

        return dp[m][n];
    }
};

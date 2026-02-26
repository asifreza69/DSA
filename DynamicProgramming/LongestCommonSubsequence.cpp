// LeetCode 1143: Longest Common Subsequence
//
// Approach 1: Top-Down Dynamic Programming (Memoization)
// Approach 2: Bottom-Up Dynamic Programming (Tabulation)
//
// Idea:
// - If characters match → 1 + result of remaining strings
// - If not match → take maximum of skipping one character
//
// Recurrence:
//      if text1[i] == text2[j]
//          dp[i][j] = 1 + dp[i+1][j+1]
//      else
//          dp[i][j] = max(dp[i+1][j], dp[i][j+1])
//
// Time Complexity: O(n * m)
// Space Complexity: O(n * m)

class Solution {
public:
    int t[1001][1001];  // Memo table for recursion

    // ----------- Top-Down (Memoization) -----------
    int solve(string& text1, string& text2, int i, int j) {

        // Base case
        if (i >= text1.size() || j >= text2.size()) {
            return 0;
        }

        // If already computed
        if (t[i][j] != -1) {
            return t[i][j];
        }

        // If characters match
        if (text1[i] == text2[j]) {
            return t[i][j] = 1 + solve(text1, text2, i + 1, j + 1);
        }

        // If characters do not match
        return t[i][j] = max(
            solve(text1, text2, i + 1, j),
            solve(text1, text2, i, j + 1)
        );
    }

    int longestCommonSubsequence(string text1, string text2) {

        // Uncomment below to use Top-Down version
        /*
        memset(t, -1, sizeof(t));
        return solve(text1, text2, 0, 0);
        */

        // ----------- Bottom-Up (Tabulation) -----------

        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];
    }
};

// LeetCode 516: Longest Palindromic Subsequence
//
// Approach: Bottom-Up Dynamic Programming
//
// Idea:
// - A subsequence is palindrome if characters at both ends match.
//
// - Let dp[i][j] = length of longest palindromic subsequence
//   in substring from index i to j.
//
// - If characters match:
//      dp[i][j] = 2 + dp[i+1][j-1]
//
// - If characters do not match:
//      dp[i][j] = max(dp[i+1][j], dp[i][j-1])
//
// - Base case:
//      Single character → palindrome of length 1
//
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)

class Solution {
public:
    int longestPalindromeSubseq(string s) {

        int n = s.size();

        // DP table
        vector<vector<int>> t(n, vector<int>(n, 0));

        // l = length of substring
        for (int l = 1; l <= n; l++) {

            for (int i = 0; i + l - 1 < n; i++) {

                int j = i + l - 1;

                // Base case: single character
                if (l == 1) {
                    t[i][i] = 1;
                }

                // If characters match
                else if (s[i] == s[j]) {
                    t[i][j] = 2 + t[i + 1][j - 1];
                }

                // If characters do not match
                else {
                    t[i][j] = max(t[i + 1][j], t[i][j - 1]);
                }
            }
        }

        return t[0][n - 1];
    }
};

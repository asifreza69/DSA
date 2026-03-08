// LeetCode 1312: Minimum Insertion Steps to Make a String Palindrome
//
// Approach: Bottom-Up Dynamic Programming
//
// Idea:
// - We want the minimum insertions needed to convert the string into a palindrome.
//
// - Let dp[i][j] = minimum insertions needed to make substring s[i..j] a palindrome.
//
// - If characters match:
//      dp[i][j] = dp[i+1][j-1]
//
// - If characters do not match:
//      dp[i][j] = 1 + min(dp[i][j-1], dp[i+1][j])
//
// - Base case:
//      Single character substring → already palindrome → 0 insertions
//
// Time Complexity: O(n²)
// Space Complexity: O(n²)

class Solution {
public:
    int minInsertions(string s) {

        int n = s.size();

        // DP table
        vector<vector<int>> grid(n, vector<int>(n));

        // l = length of substring
        for (int l = 1; l <= n; l++) {

            for (int i = 0; i + l - 1 < n; i++) {

                int j = i + l - 1;

                // Base case: single character
                if (l == 1) {
                    grid[i][i] = 0;
                }

                // Characters match
                else if (s[i] == s[j]) {
                    grid[i][j] = grid[i + 1][j - 1];
                }

                // Characters do not match
                else {
                    grid[i][j] = 1 + min(grid[i][j - 1], grid[i + 1][j]);
                }
            }
        }

        return grid[0][n - 1];
    }
};

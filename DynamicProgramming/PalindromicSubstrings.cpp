// LeetCode 647: Palindromic Substrings
//
// Approach: Bottom-Up Dynamic Programming
//
// Idea:
// - A substring is palindrome if:
//      1. Single character → always palindrome
//      2. Two characters → both characters equal
//      3. More than two characters:
//           s[i] == s[j] AND substring(i+1, j-1) is palindrome
//
// - dp[i][j] = true if substring from i to j is palindrome
//
// - Iterate over substring lengths and fill DP table.
//
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)

class Solution {
public:
    int countSubstrings(string s) {

        int n = s.size();
        int count = 0;

        // DP table
        vector<vector<bool>> grid(n, vector<bool>(n, false));

        // l = length of substring
        for (int l = 1; l <= n; l++) {

            for (int i = 0; i + l - 1 < n; i++) {

                int j = i + l - 1;

                // Case 1: single character
                if (l == 1) {
                    grid[i][j] = true;
                }

                // Case 2: two characters
                else if (i + 1 == j && s[i] == s[j]) {
                    grid[i][j] = true;
                }

                // Case 3: more than two characters
                else {
                    grid[i][j] = (s[i] == s[j] && grid[i + 1][j - 1]);
                }

                // Count palindrome substrings
                if (grid[i][j]) {
                    count++;
                }
            }
        }

        return count;
    }
};

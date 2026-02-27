// LeetCode 1092: Shortest Common Supersequence
//
// Approach: Bottom-Up Dynamic Programming (Tabulation)
//
// Idea:
// - We build a DP table where:
//      dp[i][j] = length of shortest common supersequence
//      for first i characters of str1
//      and first j characters of str2.
//
// - If characters match:
//      dp[i][j] = 1 + dp[i-1][j-1]
//
// - If characters do not match:
//      dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1])
//
// - After filling the table, we backtrack
//   to construct the actual supersequence.
//
// Time Complexity: O(n * m)
// Space Complexity: O(n * m)

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {

        int n = str1.size();
        int m = str2.size();

        // DP table
        vector<vector<int>> t(n + 1, vector<int>(m + 1));

        // Fill base cases
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {

                if (i == 0 || j == 0) {
                    t[i][j] = i + j;
                }
                else if (str1[i - 1] == str2[j - 1]) {
                    t[i][j] = 1 + t[i - 1][j - 1];
                }
                else {
                    t[i][j] = 1 + min(t[i - 1][j], t[i][j - 1]);
                }
            }
        }

        // Reconstruct the answer
        string result = "";
        int i = n, j = m;

        while (i > 0 && j > 0) {

            if (str1[i - 1] == str2[j - 1]) {
                result.push_back(str1[i - 1]);
                i--;
                j--;
            }
            else if (t[i - 1][j] < t[i][j - 1]) {
                result.push_back(str1[i - 1]);
                i--;
            }
            else {
                result.push_back(str2[j - 1]);
                j--;
            }
        }

        // Add remaining characters
        while (i > 0) {
            result.push_back(str1[i - 1]);
            i--;
        }

        while (j > 0) {
            result.push_back(str2[j - 1]);
            j--;
        }

        // Reverse because we built it backwards
        reverse(result.begin(), result.end());

        return result;
    }
};

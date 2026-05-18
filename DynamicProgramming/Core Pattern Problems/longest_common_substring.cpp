class Solution {
public:
    int longCommSubstr(string& s1,
                       string& s2) {

        int n = s1.size();
        int m = s2.size();

        int maxi = 0;

        // dp[i][j] =
        // length of longest common substring
        // ending at s1[i-1] and s2[j-1]
        vector<vector<int>> dp(
            n + 1,
            vector<int>(m + 1, 0)
        );

        for(int i = 1; i <= n; i++) {

            for(int j = 1; j <= m; j++) {

                // Characters match:
                // extend previous substring
                if(s1[i - 1] == s2[j - 1]) {

                    dp[i][j] =
                        1 + dp[i - 1][j - 1];

                    maxi =
                        max(maxi,
                            dp[i][j]);
                }
                else {
                    // Substring must be contiguous,
                    // so reset to 0
                    dp[i][j] = 0;
                }
            }
        }

        return maxi;
    }
};

/*
==========================
🔥 LONGEST COMMON
SUBSTRING
==========================

Goal:
Find the length of the longest
contiguous substring common to
both strings.

--------------------------------

🧠 Core Idea:

Unlike LCS, characters must be
continuous.

If characters match:
extend diagonal value.

If they don't match:
reset to 0.

--------------------------------

State:

dp[i][j]

= length of longest common
substring ending at:

s1[i-1]
s2[j-1]

--------------------------------

Recurrence:

If s1[i-1] == s2[j-1]:
    dp[i][j] =
    1 + dp[i-1][j-1]

Else:
    dp[i][j] = 0

--------------------------------

Answer:

Maximum value in the DP table.

--------------------------------

Example:

s1 = "abcde"
s2 = "abfce"

Longest common substring:
"ab"

Length = 2

--------------------------------

⏱️ Time Complexity:
O(n × m)

--------------------------------

🧠 Space Complexity:
O(n × m)

Can be optimized to O(m).

--------------------------------

🧩 Pattern:
String DP

--------------------------------

🎯 Category:
Dynamic Programming → LCS Variant

--------------------------------

🧠 Interview One-Liner:

If characters match, extend the
diagonal; otherwise reset to 0.

*/

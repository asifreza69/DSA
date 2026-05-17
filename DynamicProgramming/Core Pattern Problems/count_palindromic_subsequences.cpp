class Solution {
public:
    int countPS(string &s) {

        int n = s.size();

        vector<vector<int>> dp(
            n,
            vector<int>(n, 0)
        );

        // Every single character is a palindrome
        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        // Length of substring
        for(int len = 2; len <= n; len++) {

            for(int i = 0; i + len - 1 < n; i++) {

                int j = i + len - 1;

                if(s[i] == s[j]) {

                    /*
                    All palindromes from:
                    dp[i+1][j]
                    dp[i][j-1]

                    Plus one new palindrome
                    formed by using s[i] and s[j].
                    */
                    dp[i][j] =
                        1 +
                        dp[i + 1][j] +
                        dp[i][j - 1];
                }
                else {

                    /*
                    Inclusion-Exclusion:
                    Add both ranges, subtract overlap.
                    */
                    dp[i][j] =
                        dp[i + 1][j] +
                        dp[i][j - 1] -
                        dp[i + 1][j - 1];
                }
            }
        }

        return dp[0][n - 1];
    }
};

/*
==========================
🔥 COUNT PALINDROMIC
SUBSEQUENCES
==========================

Goal:
Count all palindromic
subsequences in a string.

--------------------------------

🧠 Core Idea:

Let dp[i][j] represent the number
of palindromic subsequences in
substring s[i...j].

--------------------------------

Case 1:
s[i] == s[j]

dp[i][j] =
1 + dp[i+1][j] + dp[i][j-1]

Why +1?
Because s[i] and s[j] together
form at least one new palindrome.

--------------------------------

Case 2:
s[i] != s[j]

dp[i][j] =
dp[i+1][j] +
dp[i][j-1] -
dp[i+1][j-1]

Use inclusion-exclusion to avoid
double counting.

--------------------------------

Base Case:

dp[i][i] = 1

Each single character is a
palindromic subsequence.

--------------------------------

Example:

s = "aaa"

Palindromic subsequences:
"a", "a", "a",
"aa", "aa", "aa",
"aaa"

Answer = 7

--------------------------------

⏱️ Time Complexity:
O(n²)

--------------------------------

🧠 Space Complexity:
O(n²)

--------------------------------

🧩 Pattern:
Interval DP

--------------------------------

🎯 Category:
Dynamic Programming → Palindrome DP

--------------------------------

🧠 Interview One-Liner:

Use interval DP with
inclusion-exclusion to count
palindromic subsequences.

*/

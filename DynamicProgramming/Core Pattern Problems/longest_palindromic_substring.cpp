class Solution {
public:
    string getLongestPal(string &s) {

        int n = s.size();

        if(n == 0) return "";

        int maxLen = 1;
        string ans;
        ans.push_back(s[0]);

        // dp[i][j] = true if s[i...j]
        // is a palindrome
        vector<vector<bool>> dp(
            n,
            vector<bool>(n, false)
        );

        // Single characters
        for(int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // Check substrings of length 2..n
        for(int len = 2; len <= n; len++) {

            for(int i = 0;
                i + len - 1 < n;
                i++) {

                int j = i + len - 1;

                // Length 2 palindrome
                if(len == 2 &&
                   s[i] == s[j]) {

                    dp[i][j] = true;
                }

                // Length >= 3 palindrome
                else if(s[i] == s[j] &&
                        dp[i + 1][j - 1]) {

                    dp[i][j] = true;
                }

                // Update answer
                if(dp[i][j] &&
                   len > maxLen) {

                    maxLen = len;
                    ans = s.substr(i, len);
                }
            }
        }

        return ans;
    }
};

/*
==========================
🔥 LONGEST PALINDROMIC
SUBSTRING
==========================

Goal:
Find the longest contiguous
substring that is a palindrome.

--------------------------------

🧠 Core Idea:

A substring s[i...j] is a
palindrome if:

1. s[i] == s[j]
2. Inner substring s[i+1...j-1]
   is also a palindrome.

--------------------------------

State:

dp[i][j]

= true if substring s[i...j]
is a palindrome.

--------------------------------

Recurrence:

If len == 2:
    dp[i][j] =
    (s[i] == s[j])

If len >= 3:
    dp[i][j] =
    (s[i] == s[j]) &&
    dp[i+1][j-1]

--------------------------------

Base Case:

dp[i][i] = true

Every single character is a
palindrome.

--------------------------------

Example:

s = "babad"

Longest palindrome:
"bab" or "aba"

--------------------------------

⏱️ Time Complexity:
O(n²)

--------------------------------

🧠 Space Complexity:
O(n²)

--------------------------------

🧩 Pattern:
Palindrome DP / Interval DP

--------------------------------

🎯 Category:
Dynamic Programming → String DP

--------------------------------

🧠 Interview One-Liner:

A substring is a palindrome if
its endpoints match and the
inner substring is also a
palindrome.

*/

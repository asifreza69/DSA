class Solution {
public:
    int t[501][501];

    int solve(int i,
              int j,
              string &s) {

        // Empty or single character
        if(i >= j) {
            return 0;
        }

        // Memoized result
        if(t[i][j] != -1) {
            return t[i][j];
        }

        // Characters already match
        if(s[i] == s[j]) {
            return t[i][j] =
                solve(i + 1,
                      j - 1,
                      s);
        }

        /*
        Insert one character:

        1. Match s[i] by inserting it near j
        2. Match s[j] by inserting it near i
        */
        return t[i][j] =
            1 + min(
                    solve(i + 1, j, s),
                    solve(i, j - 1, s)
                );
    }

    int findMinInsertions(string &s) {

        memset(t, -1, sizeof(t));

        return solve(0,
                     s.size() - 1,
                     s);
    }
};

/*
==========================
🔥 MINIMUM INSERTIONS
TO FORM PALINDROME
==========================

Goal:
Find the minimum number of
insertions needed to make the
string a palindrome.

--------------------------------

🧠 Core Idea:

Compare characters at both ends.

If they match:
No insertion needed.

If they don't match:
Insert one character and solve
the smaller subproblem.

--------------------------------

State:

solve(i, j)

= minimum insertions needed
for substring s[i...j].

--------------------------------

Recurrence:

If s[i] == s[j]:
    solve(i, j) =
    solve(i+1, j-1)

Else:
    solve(i, j) =
    1 + min(
        solve(i+1, j),
        solve(i, j-1)
    )

--------------------------------

Base Case:

i >= j
→ already palindrome
→ 0 insertions

--------------------------------

Example:

s = "abcda"

Minimum insertions = 2
Result could be:
"adcbcda"

--------------------------------

Alternative Formula:

Minimum Insertions =
n - LPS

where LPS =
Longest Palindromic Subsequence

--------------------------------

⏱️ Time Complexity:
O(n²)

--------------------------------

🧠 Space Complexity:
O(n²)

+ recursion stack O(n)

--------------------------------

🧩 Pattern:
Interval DP / Palindrome DP

--------------------------------

🎯 Category:
Dynamic Programming → String DP

--------------------------------

🧠 Interview One-Liner:

If endpoints differ, insert one
character and take the minimum
of removing either end.

*/

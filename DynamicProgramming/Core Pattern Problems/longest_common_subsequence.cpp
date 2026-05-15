class Solution {
public:
    int t[1001][1001];

    int solve(int i,
              int j,
              string& s1,
              string& s2) {

        // If either string ends,
        // no common subsequence remains.
        if(i >= s1.size() ||
           j >= s2.size()) {
            return 0;
        }

        // Memoized answer
        if(t[i][j] != -1) {
            return t[i][j];
        }

        // Characters match
        if(s1[i] == s2[j]) {
            return t[i][j] =
                1 + solve(i + 1,
                          j + 1,
                          s1,
                          s2);
        }

        // Skip one character from
        // either string
        int skipS1 =
            solve(i + 1, j, s1, s2);

        int skipS2 =
            solve(i, j + 1, s1, s2);

        return t[i][j] =
            max(skipS1, skipS2);
    }

    int lcs(string& s1, string& s2) {

        memset(t, -1, sizeof(t));

        return solve(0, 0, s1, s2);
    }
};

/*
==========================
🔥 LONGEST COMMON SUBSEQUENCE
==========================

Goal:
Find the length of the longest
subsequence common to both strings.

A subsequence keeps relative
order but does not require
contiguous characters.

--------------------------------

🧠 Core Idea:

Compare characters at indices
(i, j).

Case 1:
s1[i] == s2[j]
→ include this character
→ 1 + solve(i+1, j+1)

Case 2:
Characters differ
→ skip one character from
either string.

Take the maximum.

--------------------------------

State:

solve(i, j)

= LCS length between
s1[i ... end] and
s2[j ... end]

--------------------------------

Recurrence:

If s1[i] == s2[j]:
    1 + solve(i+1, j+1)

Else:
    max(
        solve(i+1, j),
        solve(i, j+1)
    )

--------------------------------

Base Case:

If either string ends:
return 0

--------------------------------

Example:

s1 = "abcde"
s2 = "ace"

LCS = "ace"
Length = 3

--------------------------------

⏱️ Time Complexity:
O(m × n)

--------------------------------

🧠 Space Complexity:
O(m × n)

+ recursion stack O(m + n)

--------------------------------

🧩 Pattern:
String DP

--------------------------------

🎯 Category:
Dynamic Programming → LCS Pattern

--------------------------------

🧠 Interview One-Liner:

If characters match, include them.
Otherwise, skip one character from
either string and take the better
result.

*/

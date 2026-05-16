class Solution {
public:
    int m, n;
    int t[501][501];

    int solve(int i, int j,
              string& s1,
              string& s2) {

        // If s1 is exhausted,
        // append remaining chars of s2
        if(i == m) {
            return n - j;
        }

        // If s2 is exhausted,
        // append remaining chars of s1
        if(j == n) {
            return m - i;
        }

        // Memoized result
        if(t[i][j] != -1) {
            return t[i][j];
        }

        // Characters match:
        // include once
        if(s1[i] == s2[j]) {
            return t[i][j] =
                1 + solve(i + 1,
                          j + 1,
                          s1,
                          s2);
        }

        // Take char from s1
        int take1 =
            1 + solve(i + 1,
                      j,
                      s1,
                      s2);

        // Take char from s2
        int take2 =
            1 + solve(i,
                      j + 1,
                      s1,
                      s2);

        return t[i][j] =
            min(take1, take2);
    }

    int minSuperSeq(string& s1,
                    string& s2) {

        m = s1.size();
        n = s2.size();

        memset(t, -1, sizeof(t));

        return solve(0, 0, s1, s2);
    }
};

/*
==========================
🔥 SHORTEST COMMON
SUPERSEQUENCE (SCS)
==========================

Goal:
Find the length of the shortest
string that contains both s1 and
s2 as subsequences.

--------------------------------

🧠 Core Idea:

Compare characters at (i, j).

Case 1:
s1[i] == s2[j]
→ include this character once
→ 1 + solve(i+1, j+1)

Case 2:
Characters differ.

Option 1:
Take s1[i]
→ 1 + solve(i+1, j)

Option 2:
Take s2[j]
→ 1 + solve(i, j+1)

Take the minimum.

--------------------------------

State:

solve(i, j)

= length of shortest common
supersequence of
s1[i...end] and s2[j...end]

--------------------------------

Base Cases:

i == m
→ append remaining chars of s2

j == n
→ append remaining chars of s1

--------------------------------

Alternative Formula:

SCS Length =
m + n - LCS(s1, s2)

--------------------------------

Example:

s1 = "abac"
s2 = "cab"

SCS = "cabac"
Length = 5

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
Dynamic Programming → LCS Variant

--------------------------------

🧠 Interview One-Liner:

If characters match, include once.
Otherwise include one character
from either string and take the
shorter result.

*/

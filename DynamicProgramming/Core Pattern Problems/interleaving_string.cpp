class Solution {
public:
    int m, n, o;
    int t[301][301];

    /*
    i = index in s1
    j = index in s2
    k = index in s3
    Note:
    k = i + j, so memoization
    only needs (i, j).
    */
    bool solve(int i,
               int j,
               int k,
               string& s1,
               string& s2,
               string& s3) {

        // All strings consumed
        if(i == m && j == n && k == o) {
            return true;
        }

        // s3 exhausted too early
        if(k >= o) {
            return false;
        }

        // Memoized result
        if(t[i][j] != -1) {
            return t[i][j];
        }

        bool ans = false;

        // Take next char from s1
        if(i < m &&
           s1[i] == s3[k]) {

            ans = ans ||
                  solve(i + 1,
                        j,
                        k + 1,
                        s1,
                        s2,
                        s3);
        }

        // Take next char from s2
        if(j < n &&
           s2[j] == s3[k]) {

            ans = ans ||
                  solve(i,
                        j + 1,
                        k + 1,
                        s1,
                        s2,
                        s3);
        }

        return t[i][j] = ans;
    }

    bool isInterleave(string& s1,
                      string& s2,
                      string& s3) {

        m = s1.size();
        n = s2.size();
        o = s3.size();

        // Length mismatch
        if(m + n != o) {
            return false;
        }

        memset(t, -1, sizeof(t));

        return solve(0, 0, 0,
                     s1, s2, s3);
    }
};

/*
==========================
🔥 INTERLEAVING STRING
==========================

Goal:
Check whether s3 can be formed
by interleaving s1 and s2 while
preserving the order of characters
in both strings.

--------------------------------

🧠 Core Idea:

At position k in s3, the current
character can come from:

1. s1[i]
2. s2[j]

Try both possibilities.

--------------------------------

State:

solve(i, j)

i = current index in s1
j = current index in s2

k = i + j

Returns true if s3[k...]
can be formed.

--------------------------------

Recurrence:

If s1[i] == s3[k]:
    try solve(i+1, j)

If s2[j] == s3[k]:
    try solve(i, j+1)

Answer =
OR of valid choices.

--------------------------------

Base Case:

i == m and j == n
→ all characters used
→ true

--------------------------------

Example:

s1 = "abc"
s2 = "def"
s3 = "adbcef"

Answer = true

--------------------------------

⏱️ Time Complexity:
O(m × n)

--------------------------------

🧠 Space Complexity:
O(m × n)

+ recursion stack O(m + n)

--------------------------------

🧩 Pattern:
2D String DP

--------------------------------

🎯 Category:
Dynamic Programming → String DP

--------------------------------

🧠 Interview One-Liner:

At each character of s3, decide
whether it comes from s1 or s2,
and memoize by (i, j).

*/

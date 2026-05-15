class Solution {
public:
    int m, n;
    int t[1001][1001];

    int solve(int i, int j,
              string& s1,
              string& s2) {

        // s1 exhausted:
        // insert remaining chars of s2
        if(i >= m) {
            return n - j;
        }

        // s2 exhausted:
        // delete remaining chars of s1
        if(j >= n) {
            return m - i;
        }

        if(t[i][j] != -1) {
            return t[i][j];
        }

        // Characters match
        if(s1[i] == s2[j]) {
            return t[i][j] =
                solve(i + 1, j + 1, s1, s2);
        }

        // Delete s1[i]
        int del =
            1 + solve(i + 1, j, s1, s2);

        // Insert s2[j] into s1
        int insert =
            1 + solve(i, j + 1, s1, s2);

        return t[i][j] = min(insert, del);
    }

    int minOperations(string& s1, string& s2) {

        m = s1.size();
        n = s2.size();

        memset(t, -1, sizeof(t));

        return solve(0, 0, s1, s2);
    }
};

/*
==========================
🔥 MIN INSERTIONS & DELETIONS
==========================

Goal:
Convert string s1 into s2 using
only:
1. Insert
2. Delete

Return minimum operations.

--------------------------------

🧠 Core Idea:

Compare characters at indices
(i, j).

Case 1:
s1[i] == s2[j]
→ move both pointers.

Case 2:
Characters differ.

Option 1:
Delete s1[i]
→ i + 1, j

Option 2:
Insert s2[j]
→ i, j + 1

Take minimum.

--------------------------------

Base Cases:

i == m
→ insert remaining chars of s2.

j == n
→ delete remaining chars of s1.

--------------------------------

Alternative Formula:

answer =
(m - LCS) + (n - LCS)

where LCS is longest common
subsequence.

--------------------------------

⏱️ Time Complexity:
O(m × n)

--------------------------------

🧠 Space Complexity:
O(m × n)

--------------------------------

🧩 Pattern:
String DP

--------------------------------

🎯 Category:
Dynamic Programming → LCS Variant

--------------------------------

🧠 Interview One-Liner:

If characters match, move both.
Otherwise, either delete from
s1 or insert into s1 and take
the minimum cost.

*/

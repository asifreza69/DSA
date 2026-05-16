class Solution {
public:
    int m, n;
    int t[1001][1001];

    int solve(int i, int j,
              string& s1,
              string& s2) {

        // If s1 is exhausted,
        // insert all remaining chars of s2
        if(i >= m) {
            return n - j;
        }

        // If s2 is exhausted,
        // delete all remaining chars of s1
        if(j >= n) {
            return m - i;
        }

        // Characters already match
        if(s1[i] == s2[j]) {
            return solve(i + 1,
                         j + 1,
                         s1,
                         s2);
        }

        // Memoized answer
        if(t[i][j] != -1) {
            return t[i][j];
        }

        // Insert s2[j] into s1
        int insert =
            1 + solve(i,
                      j + 1,
                      s1,
                      s2);

        // Delete s1[i]
        int del =
            1 + solve(i + 1,
                      j,
                      s1,
                      s2);

        // Replace s1[i] with s2[j]
        int replace =
            1 + solve(i + 1,
                      j + 1,
                      s1,
                      s2);

        return t[i][j] =
            min({insert, del, replace});
    }

    int editDistance(string& s1, string& s2) {

        m = s1.size();
        n = s2.size();

        memset(t, -1, sizeof(t));

        return solve(0, 0, s1, s2);
    }
};

/*
==========================
🔥 EDIT DISTANCE
==========================

Goal:
Convert string s1 into s2 using
minimum operations.

Allowed operations:
1. Insert
2. Delete
3. Replace

--------------------------------

🧠 Core Idea:

Compare characters at (i, j).

Case 1:
s1[i] == s2[j]
→ no operation needed
→ move both pointers.

Case 2:
Characters differ.

Option 1:
Insert s2[j]
→ i, j+1

Option 2:
Delete s1[i]
→ i+1, j

Option 3:
Replace s1[i]
→ i+1, j+1

Take minimum.

--------------------------------

State:

solve(i, j)

= minimum operations to convert
s1[i...end] into s2[j...end]

--------------------------------

Base Cases:

i == m
→ insert remaining chars of s2

j == n
→ delete remaining chars of s1

--------------------------------

Recurrence:

If s1[i] == s2[j]:
    solve(i+1, j+1)

Else:
    1 + min(
        solve(i, j+1),     // insert
        solve(i+1, j),     // delete
        solve(i+1, j+1)    // replace
    )

--------------------------------

Example:

s1 = "horse"
s2 = "ros"

Answer = 3

horse → rorse  (replace h→r)
rorse → rose   (delete r)
rose  → ros    (delete e)

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
Dynamic Programming → Edit Distance Pattern

--------------------------------

🧠 Interview One-Liner:

When characters differ, try
insert, delete, and replace,
and choose the minimum cost.

*/

class Solution {
public:
    // Function to find the nth Catalan number.
    int findCatalan(int n) {

        // Base cases
        if(n == 0 || n == 1) {
            return 1;
        }

        vector<int> dp(n + 1, 0);

        dp[0] = 1;
        dp[1] = 1;

        // Build Catalan numbers
        for(int i = 2; i <= n; i++) {

            int total = 0;

            // Catalan recurrence:
            // C(i) = Σ C(j) * C(i-j-1)
            for(int j = 0; j < i; j++) {
                total += dp[j] * dp[i - j - 1];
            }

            dp[i] = total;
        }

        return dp[n];
    }
};

/*
==========================
🔥 CATALAN NUMBER
==========================

Goal:
Find the nth Catalan number.

--------------------------------

🧠 Catalan Sequence:

C0 = 1
C1 = 1
C2 = 2
C3 = 5
C4 = 14
C5 = 42

--------------------------------

🧠 Recurrence Relation:

C(n) = Σ C(i) * C(n-i-1)
       for i = 0 to n-1

--------------------------------

Why This Works?

Choose one element as root.

- Left subtree uses i nodes.
- Right subtree uses n-i-1 nodes.

Total ways:
Catalan(left) × Catalan(right)

Sum over all possible roots.

--------------------------------

Applications:

- Number of BSTs with n nodes
- Valid parentheses combinations
- Mountain ranges
- Polygon triangulations
- Non-crossing chords

--------------------------------

Algorithm:

1. dp[0] = dp[1] = 1
2. For each n:
      try all partitions.
3. Multiply left and right ways.
4. Sum them.

--------------------------------

⏱️ Time Complexity:
O(n²)

--------------------------------

🧠 Space Complexity:
O(n)

--------------------------------

🧩 Pattern:
Counting DP

--------------------------------

🎯 Category:
Dynamic Programming → Catalan Pattern

--------------------------------

🧠 Interview One-Liner:

Catalan number counts structures
formed by partitioning into left
and right independent subproblems.

*/

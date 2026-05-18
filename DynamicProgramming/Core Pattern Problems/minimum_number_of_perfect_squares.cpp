class Solution {
public:
    int dp[10001];

    int solve(int n) {

        // Exact sum formed
        if(n == 0) {
            return 0;
        }

        // Memoized result
        if(dp[n] != -1) {
            return dp[n];
        }

        // Worst case:
        // 1^2 + 1^2 + ... + 1^2
        int ans = n;

        // Try every perfect square <= n
        for(int i = 1; i * i <= n; i++) {

            int square = i * i;

            int smallAns =
                1 + solve(n - square);

            ans =
                min(ans, smallAns);
        }

        return dp[n] = ans;
    }

    int minSquares(int n) {

        memset(dp, -1, sizeof(dp));

        return solve(n);
    }
};

/*
==========================
🔥 MINIMUM NUMBER OF
PERFECT SQUARES
==========================

Goal:
Find the minimum number of
perfect square numbers whose
sum equals n.

--------------------------------

🧠 Core Idea:

Try every square:

1², 2², 3², ...

Choose the one that gives the
minimum count.

--------------------------------

State:

solve(n)

= minimum number of perfect
squares needed to form n.

--------------------------------

Recurrence:

solve(n) =
1 + min(
    solve(n - 1²),
    solve(n - 2²),
    solve(n - 3²),
    ...
)

--------------------------------

Base Case:

n == 0
→ return 0

--------------------------------

Example:

n = 12

12 = 4 + 4 + 4

Answer = 3

--------------------------------

n = 13

13 = 4 + 9

Answer = 2

--------------------------------

⏱️ Time Complexity:
O(n × √n)

--------------------------------

🧠 Space Complexity:
O(n)

--------------------------------

🧩 Pattern:
Unbounded Knapsack / Min Coins

--------------------------------

🎯 Category:
Dynamic Programming

--------------------------------

🧠 Interview One-Liner:

Treat each perfect square as a
coin denomination and find the
minimum number of coins needed.

*/

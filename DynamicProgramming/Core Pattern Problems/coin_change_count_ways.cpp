class Solution {
public:
    int n;
    vector<vector<int>> t;

    int solve(int i,
              vector<int>& coins,
              int sum) {

        // Target formed
        if(sum == 0)
            return 1;

        // No coins left
        if(i >= n)
            return 0;

        // Memoized result
        if(t[i][sum] != -1)
            return t[i][sum];

        int take = 0;

        // Use current coin again
        // (unlimited usage allowed)
        if(sum >= coins[i]) {
            take =
                solve(i,
                      coins,
                      sum - coins[i]);
        }

        // Skip current coin
        int skip =
            solve(i + 1,
                  coins,
                  sum);

        // Total ways
        return t[i][sum] =
            take + skip;
    }

    int count(vector<int>& coins,
              int sum) {

        n = coins.size();

        t.resize(n + 1,
                 vector<int>(sum + 1, -1));

        return solve(0, coins, sum);
    }
};

/*
==========================
🔥 COIN CHANGE
(COUNT NUMBER OF WAYS)
==========================

Goal:
Count the number of distinct
ways to make the target sum.

Each coin can be used
unlimited times.

--------------------------------

🧠 Core Idea:

For each coin, we have
two choices:

1. Take it
   (stay at same index because
    coin can be reused)

2. Skip it
   (move to next coin)

Total ways =
take + skip

--------------------------------

State:

solve(i, sum)

= number of ways to form
'sum' using coins from
index i onward.

--------------------------------

Recurrence:

take =
solve(i, sum - coins[i])

skip =
solve(i + 1, sum)

answer =
take + skip

--------------------------------

Base Cases:

sum == 0
→ 1 valid way found

i == n
→ 0 ways

--------------------------------

Example:

coins = [1, 2, 5]
sum = 5

Ways:
1+1+1+1+1
1+1+1+2
1+2+2
5

Answer = 4

--------------------------------

⏱️ Time Complexity:
O(n × sum)

--------------------------------

🧠 Space Complexity:
O(n × sum)

+ recursion stack O(n)

--------------------------------

🧩 Pattern:
Unbounded Knapsack

--------------------------------

🎯 Category:
Dynamic Programming → Coin Change

--------------------------------

🧠 Interview One-Liner:

For each coin, either use it
again or skip it; total ways
are the sum of both choices.

*/

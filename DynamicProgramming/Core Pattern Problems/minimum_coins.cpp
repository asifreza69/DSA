class Solution {
public:
    int n;
    int t[10001];

    int solve(vector<int>& coins, int sum) {

        // Invalid state
        if(sum < 0) {
            return INT_MAX;
        }

        // Exact sum formed
        if(sum == 0) {
            return 0;
        }

        // Memoized answer
        if(t[sum] != -1) {
            return t[sum];
        }

        int mini = INT_MAX;

        // Try every coin
        for(int i = 0; i < n; i++) {

            int take = solve(coins, sum - coins[i]);

            if(take != INT_MAX) {
                mini = min(mini, 1 + take);
            }
        }

        return t[sum] = mini;
    }

    int minCoins(vector<int>& coins, int sum) {

        n = coins.size();

        memset(t, -1, sizeof(t));

        int ans = solve(coins, sum);

        return (ans == INT_MAX) ? -1 : ans;
    }
};

/*
==========================
🔥 MINIMUM COINS
==========================

Goal:
Find the minimum number of coins
needed to make the target sum.

Each coin can be used unlimited times.

--------------------------------

🧠 Core Idea:

For every coin:
- take it
- solve remaining sum

Choose the minimum answer.

--------------------------------

Recurrence:

f(sum) =
min(1 + f(sum - coin))
for all coins

--------------------------------

Base Cases:

sum == 0  → 0 coins needed
sum < 0   → invalid (INT_MAX)

--------------------------------

Why Unbounded Knapsack?

Because each coin can be used
any number of times.

--------------------------------

Example:

coins = [1, 2, 5]
sum = 11

11 = 5 + 5 + 1
Answer = 3

--------------------------------

⏱️ Time Complexity:
O(n × sum)

n = number of coins

--------------------------------

🧠 Space Complexity:
O(sum)

+ recursion stack O(sum)

--------------------------------

🧩 Pattern:
Unbounded Knapsack

--------------------------------

🎯 Category:
Dynamic Programming → Coin Change

--------------------------------

🧠 Interview One-Liner:

For each target sum, try every coin
and take the minimum number of
coins among all choices.

*/

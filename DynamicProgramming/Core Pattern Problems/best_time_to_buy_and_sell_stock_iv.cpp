class Solution {
public:
    int n;

    // t[i][buy][k]
    // i    = current day
    // buy  = 1 -> can buy
    //        0 -> must sell / holding stock
    // k    = transactions remaining
    int t[1001][2][2001];

    int solve(int i,
              bool buy,
              vector<int>& prices,
              int k) {

        // No days left
        if(i >= n) {
            return 0;
        }

        // No transactions left
        if(k == 0) {
            return 0;
        }

        // Memoized result
        if(t[i][buy][k] != -1) {
            return t[i][buy][k];
        }

        int take = 0;
        int skip = 0;

        // Option 1: Buy
        if(buy) {

            take =
                -prices[i] +
                solve(i + 1,
                      false,
                      prices,
                      k);

            skip =
                solve(i + 1,
                      true,
                      prices,
                      k);
        }

        // Option 2: Sell
        else {

            take =
                prices[i] +
                solve(i + 1,
                      true,
                      prices,
                      k - 1);

            skip =
                solve(i + 1,
                      false,
                      prices,
                      k);
        }

        return t[i][buy][k] =
            max(take, skip);
    }

    int maxProfit(vector<int>& prices,
                  int k) {

        n = prices.size();

        memset(t, -1, sizeof(t));

        return solve(0,
                     true,
                     prices,
                     k);
    }
};

/*
==========================
🔥 BEST TIME TO BUY AND
SELL STOCK IV
==========================

Goal:
Find the maximum profit using
at most k transactions.

One transaction =
Buy once + Sell once.

--------------------------------

🧠 Core Idea:

At each day:

If we can buy:
1. Buy stock
2. Skip

If we are holding stock:
1. Sell stock
2. Skip

Use DP with:
(day, buyState, transactionsLeft)

--------------------------------

State:

solve(i, buy, k)

i   = current day
buy = 1 if allowed to buy
      0 if holding stock
k   = transactions remaining

Returns maximum profit from day i.

--------------------------------

Transitions:

buy == 1:
    max(
        -price[i] + solve(i+1, 0, k),
         solve(i+1, 1, k)
    )

buy == 0:
    max(
         price[i] + solve(i+1, 1, k-1),
         solve(i+1, 0, k)
    )

--------------------------------

Base Cases:

i == n
→ 0

k == 0
→ 0

--------------------------------

Example:

prices = [3,2,6,5,0,3]
k = 2

Profit = 7
(2→6) + (0→3)

--------------------------------

⏱️ Time Complexity:
O(n × 2 × k)

--------------------------------

🧠 Space Complexity:
O(n × 2 × k)

--------------------------------

🧩 Pattern:
State Machine DP

--------------------------------

🎯 Category:
Dynamic Programming → Stocks

--------------------------------

🧠 Interview One-Liner:

Use DP on day, buy/sell state,
and remaining transactions.

*/

class Solution {
public:
    int n;
    int t[1001][1001];

    // i   = current piece index
    // rod = length already used
    int solve(int i,
              vector<int>& price,
              int rod) {

        // Entire rod is used
        if(rod == n) {
            return 0;
        }

        // No more piece lengths to try
        if(i >= n) {
            return 0;
        }

        // Memoized result
        if(t[i][rod] != -1) {
            return t[i][rod];
        }

        int take = 0;

        // Piece length = i + 1
        // Unlimited reuse allowed
        if(rod + (i + 1) <= n) {
            take =
                price[i] +
                solve(i,
                      price,
                      rod + i + 1);
        }

        // Skip current piece length
        int skip =
            solve(i + 1,
                  price,
                  rod);

        return t[i][rod] =
            max(take, skip);
    }

    int cutRod(vector<int>& price) {

        n = price.size();

        memset(t, -1, sizeof(t));

        return solve(0, price, 0);
    }
};

/*
==========================
🔥 ROD CUTTING
==========================

Goal:
Given a rod of length n and
price[i] for a piece of length
(i + 1), maximize total revenue.

A piece length can be used
multiple times.

--------------------------------

🧠 Core Idea:

For every piece length, we have
two choices:

1. Take it
   (stay at same index because
    we can reuse it)

2. Skip it
   (move to next piece length)

This is exactly Unbounded
Knapsack.

--------------------------------

State:

solve(i, rod)

i   = current piece index
rod = length already used

--------------------------------

Recurrence:

take =
price[i] +
solve(i, rod + i + 1)

skip =
solve(i + 1, rod)

answer =
max(take, skip)

--------------------------------

Base Cases:

rod == n
→ rod completely filled
→ return 0

i == n
→ no more piece lengths
→ return 0

--------------------------------

Example:

price = [1, 5, 8, 9]
Rod length = 4

Best cut:
Length 2 + Length 2

Profit = 5 + 5 = 10

--------------------------------

⏱️ Time Complexity:
O(n²)

--------------------------------

🧠 Space Complexity:
O(n²)

+ recursion stack O(n)

--------------------------------

🧩 Pattern:
Unbounded Knapsack

--------------------------------

🎯 Category:
Dynamic Programming → Unbounded Knapsack

--------------------------------

🧠 Interview One-Liner:

Treat each cut length as an item
with unlimited reuse and choose
the maximum profit.

*/

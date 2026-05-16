class Solution {
public:
    int n;
    int t[1001][1001];

    int solve(int i,
              int w,
              vector<int>& val,
              vector<int>& wt) {

        // No items left or no capacity
        if(i >= n || w == 0) {
            return 0;
        }

        // Memoized result
        if(t[i][w] != -1) {
            return t[i][w];
        }

        int take = 0;

        // Include current item if possible
        if(w >= wt[i]) {
            take =
                val[i] +
                solve(i + 1,
                      w - wt[i],
                      val,
                      wt);
        }

        // Exclude current item
        int skip =
            solve(i + 1,
                  w,
                  val,
                  wt);

        return t[i][w] =
            max(take, skip);
    }

    int knapsack(int W,
                 vector<int>& val,
                 vector<int>& wt) {

        n = val.size();

        memset(t, -1, sizeof(t));

        return solve(0, W, val, wt);
    }
};

/*
==========================
🔥 0/1 KNAPSACK
==========================

Goal:
Choose items to maximize total
value such that total weight
does not exceed capacity W.

Each item can be chosen
at most once.

--------------------------------

🧠 Core Idea:

For each item, there are
two choices:

1. Take it
2. Skip it

Take the better option.

--------------------------------

State:

solve(i, w)

= maximum value obtainable
using items from index i onward
with remaining capacity w.

--------------------------------

Recurrence:

take =
val[i] + solve(i+1, w-wt[i])
if wt[i] <= w

skip =
solve(i+1, w)

answer =
max(take, skip)

--------------------------------

Base Cases:

i == n  → 0
w == 0  → 0

--------------------------------

Example:

val = [60, 100, 120]
wt  = [10, 20, 30]
W = 50

Best choice:
100 + 120 = 220

--------------------------------

⏱️ Time Complexity:
O(n × W)

--------------------------------

🧠 Space Complexity:
O(n × W)

+ recursion stack O(n)

--------------------------------

🧩 Pattern:
Take / Skip DP

--------------------------------

🎯 Category:
Dynamic Programming → 0/1 Knapsack

--------------------------------

🧠 Interview One-Liner:

For each item, either include it
if it fits or exclude it, and
take the maximum value.

*/

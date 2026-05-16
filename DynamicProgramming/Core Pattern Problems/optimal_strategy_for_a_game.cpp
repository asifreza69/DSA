class Solution {
public:
    int n;
    int t[1001][1001];

    int solve(int i, int j, vector<int>& arr) {

        // No coins left
        if(i > j) {
            return 0;
        }

        // Only one coin left
        if(i == j) {
            return arr[i];
        }

        // Memoized result
        if(t[i][j] != -1) {
            return t[i][j];
        }

        /*
        If we pick arr[i], opponent plays optimally
        and will leave us the minimum possible value.
        */
        int takeLeft =
            arr[i] +
            min(
                solve(i + 2, j, arr),
                solve(i + 1, j - 1, arr)
            );

        /*
        If we pick arr[j], opponent plays optimally
        and will leave us the minimum possible value.
        */
        int takeRight =
            arr[j] +
            min(
                solve(i, j - 2, arr),
                solve(i + 1, j - 1, arr)
            );

        // We choose the better option
        return t[i][j] =
            max(takeLeft, takeRight);
    }

    int maximumAmount(vector<int>& arr) {

        n = arr.size();

        memset(t, -1, sizeof(t));

        return solve(0, n - 1, arr);
    }
};

/*
==========================
🔥 OPTIMAL STRATEGY
FOR A GAME
==========================

Goal:
Two players pick coins from
either end of the array.

Both play optimally.

Return the maximum amount the
first player can collect.

--------------------------------

🧠 Core Idea:

At every step, the player has
two choices:

1. Pick left coin.
2. Pick right coin.

Since the opponent also plays
optimally, they will force us
into the worst possible future.

So:
- We choose MAX.
- Opponent causes MIN.

--------------------------------

State:

solve(i, j)

= maximum amount current player
can collect from subarray
arr[i...j]

--------------------------------

Transition:

Pick left:
arr[i] +
min(
    solve(i+2, j),
    solve(i+1, j-1)
)

Pick right:
arr[j] +
min(
    solve(i, j-2),
    solve(i+1, j-1)
)

Answer:
max(pick left, pick right)

--------------------------------

Why MIN?

After we pick a coin, opponent
gets to move and will choose the
option that minimizes our future
gain.

--------------------------------

Example:

arr = [8, 15, 3, 7]

Best strategy:
Pick 7 first.

Maximum amount = 22

--------------------------------

⏱️ Time Complexity:
O(n²)

--------------------------------

🧠 Space Complexity:
O(n²)

+ recursion stack O(n)

--------------------------------

🧩 Pattern:
Minimax DP / Interval DP

--------------------------------

🎯 Category:
Dynamic Programming → Game Theory

--------------------------------

🧠 Interview One-Liner:

For every interval, try picking
either end and assume the
opponent leaves you with the
minimum possible future value.

*/

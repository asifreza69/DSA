class Solution {
public:
    vector<vector<int>> t;

    // sum = current sum formed
    // n   = number of dice remaining
    int solve(int sum,
              int m,
              int n,
              int x) {

        // All dice used
        if(n == 0) {
            return (sum == x) ? 1 : 0;
        }

        // Memoized result
        if(t[sum][n] != -1) {
            return t[sum][n];
        }

        int ways = 0;

        // Try every face value
        for(int face = 1; face <= m; face++) {

            if(sum + face <= x) {
                ways +=
                    solve(sum + face,
                          m,
                          n - 1,
                          x);
            }
        }

        return t[sum][n] = ways;
    }

    int noOfWays(int m,
                 int n,
                 int x) {

        // sum ranges: 0...x
        // dice remaining: 0...n
        t.resize(x + 1,
                 vector<int>(n + 1, -1));

        return solve(0, m, n, x);
    }
};

/*
==========================
🔥 DICE THROW
==========================

Goal:
Count the number of ways to get
sum x using n dice, where each
die has faces from 1 to m.

--------------------------------

🧠 Core Idea:

For each die, try every face
value from 1 to m and recursively
solve for the remaining dice.

Total ways =
sum of all valid choices.

--------------------------------

State:

solve(sum, n)

sum = current accumulated sum
n   = dice remaining

--------------------------------

Recurrence:

ways = 0

for face = 1 to m:
    if sum + face <= x:
        ways +=
            solve(sum + face,
                  n - 1)

--------------------------------

Base Case:

n == 0

If sum == x:
    return 1

Else:
    return 0

--------------------------------

Example:

m = 6
n = 2
x = 7

Ways:
(1,6)
(2,5)
(3,4)
(4,3)
(5,2)
(6,1)

Answer = 6

--------------------------------

⏱️ Time Complexity:
O(x × n × m)

--------------------------------

🧠 Space Complexity:
O(x × n)

+ recursion stack O(n)

--------------------------------

🧩 Pattern:
Counting DP

--------------------------------

🎯 Category:
Dynamic Programming → Count Ways

--------------------------------

🧠 Interview One-Liner:

For each die, try every face
value and add the number of
ways to form the remaining sum.

*/

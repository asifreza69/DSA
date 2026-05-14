class Solution {
public:
    int maxProduct(int n) {

        // dp[i] = maximum product obtainable
        // by breaking integer i
        vector<int> dp(n + 1, 0);

        // Build answer bottom-up
        for(int i = 2; i <= n; i++) {

            int maxi = 0;

            // Split i into j and (i-j)
            for(int j = 1; j < i; j++) {

                // Either use number directly
                // or further break it
                int left = max(j, dp[j]);
                int right = max(i - j, dp[i - j]);

                // Product of both parts
                int product = left * right;

                maxi = max(maxi, product);
            }

            dp[i] = maxi;
        }

        return dp[n];
    }
};

/*
==========================
🔥 INTEGER BREAK
==========================

Goal:
Break integer n into at least
two positive integers such that
their product is maximum.

--------------------------------

🧠 Core Idea:

For every split:
n = j + (n-j)

For each part, choose:
1. Use the number directly
2. Break it further

Take maximum product.

--------------------------------

Recurrence:

dp[i] =
max(
    max(j, dp[j]) *
    max(i-j, dp[i-j])
)

for all j from 1 to i-1

--------------------------------

Example:

n = 10

Best split:
10 = 3 + 3 + 4

Product = 36

--------------------------------

Why max(j, dp[j])?

Because sometimes not breaking
a number gives better product.

Example:
For 4:
- break => 2 * 2 = 4
- use directly => 4

Choose maximum.

--------------------------------

⏱️ Time Complexity:
O(n²)

--------------------------------

🧠 Space Complexity:
O(n)

--------------------------------

🧩 Pattern:
Partition DP

--------------------------------

🎯 Category:
Dynamic Programming → Integer Partition

--------------------------------

🧠 Interview One-Liner:

Try every split of the integer,
and for each part decide whether
to keep it as is or break it
further.

*/

class Solution {
public:
    int n;
    vector<vector<int>> dp;

    /*
    sum = remaining capacity up to totalSum/2

    We try to fill this capacity as much as possible.
    The smaller the leftover capacity, the closer the
    subset sum is to totalSum/2.
    */
    int solve(int i,
              int sum,
              vector<int>& arr) {

        // No elements left
        // Return unused capacity
        if(i >= n) {
            return sum;
        }

        // Memoized result
        if(dp[i][sum] != -1) {
            return dp[i][sum];
        }

        // Take current element
        int take = INT_MAX;
        if(arr[i] <= sum) {
            take =
                solve(i + 1,
                      sum - arr[i],
                      arr);
        }

        // Skip current element
        int skip =
            solve(i + 1,
                  sum,
                  arr);

        // Min leftover capacity
        return dp[i][sum] =
            min(take, skip);
    }

    int minDifference(vector<int>& arr) {

        int totalSum =
            accumulate(arr.begin(),
                       arr.end(),
                       0);

        n = arr.size();

        int target = totalSum / 2;

        dp.resize(
            n + 1,
            vector<int>(target + 1, -1)
        );

        // Remaining unused capacity
        int remaining =
            solve(0, target, arr);

        // Best subset sum near target
        int subset1 =
            target - remaining;

        int subset2 =
            totalSum - subset1;

        return abs(subset1 - subset2);
    }
};

/*
==========================
🔥 MINIMUM SUM PARTITION
==========================

Goal:
Partition the array into two
subsets such that the absolute
difference of their sums is
minimum.

--------------------------------

🧠 Core Idea:

If totalSum = S,
we want one subset sum as close
as possible to S/2.

Then:
subset1 = bestSum
subset2 = S - bestSum

Difference =
|subset1 - subset2|

--------------------------------

State:

solve(i, sum)

= minimum unused capacity after
considering elements from i.

--------------------------------

Interpretation:

If target = totalSum/2,
we try to fill the knapsack as
much as possible.

--------------------------------

Choices:

1. Take arr[i]
2. Skip arr[i]

Return the minimum remaining
capacity.

--------------------------------

Example:

arr = [1, 6, 11, 5]

totalSum = 23
target = 11

Best subset sum = 11
Other subset = 12

Answer = 1

--------------------------------

⏱️ Time Complexity:
O(n × totalSum)

--------------------------------

🧠 Space Complexity:
O(n × totalSum)

--------------------------------

🧩 Pattern:
0/1 Knapsack
Subset Sum Variant

--------------------------------

🎯 Category:
Dynamic Programming

--------------------------------

🧠 Interview One-Liner:

Find the subset sum closest to
half of the total sum.

*/

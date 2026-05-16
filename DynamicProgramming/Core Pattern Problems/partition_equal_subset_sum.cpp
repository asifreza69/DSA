class Solution {
public:
    int n;
    vector<vector<int>> t;

    bool solve(int i,
               vector<int>& arr,
               int sum) {

        // Target formed
        if(sum == 0) {
            return true;
        }

        // No elements left
        if(i >= n) {
            return false;
        }

        // Memoized result
        if(t[i][sum] != -1) {
            return t[i][sum];
        }

        bool take = false;

        // Include current element
        if(sum >= arr[i]) {
            take =
                solve(i + 1,
                      arr,
                      sum - arr[i]);
        }

        // Exclude current element
        bool skip =
            solve(i + 1,
                  arr,
                  sum);

        return t[i][sum] =
            (take || skip);
    }

    bool equalPartition(vector<int>& arr) {

        n = arr.size();

        int totalSum =
            accumulate(arr.begin(),
                       arr.end(),
                       0);

        // Odd total cannot be split equally
        if(totalSum % 2 != 0) {
            return false;
        }

        int target = totalSum / 2;

        t.resize(n + 1,
                 vector<int>(target + 1, -1));

        return solve(0, arr, target);
    }
};

/*
==========================
🔥 PARTITION EQUAL
SUBSET SUM
==========================

Goal:
Determine whether the array can
be divided into two subsets with
equal sum.

--------------------------------

🧠 Core Idea:

If total sum is S, both subsets
must have sum S/2.

So the problem reduces to:

"Is there a subset whose sum
equals S/2?"

--------------------------------

Step 1:
Compute total sum.

If total sum is odd:
return false.

Step 2:
Run Subset Sum with
target = totalSum / 2.

--------------------------------

State:

solve(i, sum)

= Can we form 'sum' using
elements from index i onward?

--------------------------------

Recurrence:

take =
solve(i+1, sum-arr[i])

skip =
solve(i+1, sum)

answer =
take OR skip

--------------------------------

Base Cases:

sum == 0  → true
i == n    → false

--------------------------------

Example:

arr = [1, 5, 11, 5]

Total = 22
Target = 11

Subset [11]
Other subset [1, 5, 5]

Answer = true

--------------------------------

⏱️ Time Complexity:
O(n × target)

where target = totalSum / 2

--------------------------------

🧠 Space Complexity:
O(n × target)

+ recursion stack O(n)

--------------------------------

🧩 Pattern:
0/1 Knapsack / Subset Sum

--------------------------------

🎯 Category:
Dynamic Programming → Partition DP

--------------------------------

🧠 Interview One-Liner:

Convert the problem into checking
whether a subset with sum equal
to half of the total sum exists.

*/

class Solution {
public:
    int t[201][10001];

    bool solve(int i,
               vector<int>& arr,
               int sum) {

        // Target formed
        if(sum == 0) {
            return true;
        }

        // No elements left
        if(i >= arr.size()) {
            return false;
        }

        // Memoized result
        if(t[i][sum] != -1) {
            return t[i][sum];
        }

        bool take = false;

        // Include current element
        if(sum - arr[i] >= 0) {
            take = solve(i + 1,
                         arr,
                         sum - arr[i]);
        }

        // Exclude current element
        bool skip = solve(i + 1,
                          arr,
                          sum);

        return t[i][sum] = (take || skip);
    }

    bool isSubsetSum(vector<int>& arr, int sum) {

        memset(t, -1, sizeof(t));

        return solve(0, arr, sum);
    }
};

/*
==========================
🔥 SUBSET SUM
==========================

Goal:
Determine whether there exists
a subset whose sum equals target.

Each element can be used
at most once.

--------------------------------

🧠 Core Idea:

For every element, we have
two choices:

1. Take it
2. Skip it

If any choice reaches
sum = 0, answer is true.

--------------------------------

State:

solve(i, sum)

= Can we form 'sum' using
elements from index i onward?

--------------------------------

Recurrence:

solve(i, sum) =
take OR skip

where:

take = solve(i+1, sum-arr[i])
skip = solve(i+1, sum)

--------------------------------

Base Cases:

sum == 0  → true
i == n    → false

--------------------------------

Example:

arr = [3, 34, 4, 12, 5, 2]
sum = 9

Subset:
4 + 5 = 9

Answer = true

--------------------------------

⏱️ Time Complexity:
O(n × sum)

--------------------------------

🧠 Space Complexity:
O(n × sum)

+ recursion stack O(n)

--------------------------------

🧩 Pattern:
0/1 Knapsack

--------------------------------

🎯 Category:
Dynamic Programming → Subset DP

--------------------------------

🧠 Interview One-Liner:

For each element, either include
it in the subset or exclude it;
if any path makes the target
sum zero, return true.

*/

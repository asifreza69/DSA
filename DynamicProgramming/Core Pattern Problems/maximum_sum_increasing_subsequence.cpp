class Solution {
public:
    int n;
    int t[1001][1001];

    /*
    p = index of previously selected element
    i = current index
    */
    int solve(int p,
              int i,
              vector<int>& arr) {

        // No elements left
        if(i >= n) {
            return 0;
        }

        // Memoized result
        if(p != -1 &&
           t[p][i] != -1) {
            return t[p][i];
        }

        int take = 0;

        // Can include current element
        if(p == -1 ||
           arr[p] < arr[i]) {

            take =
                arr[i] +
                solve(i,
                      i + 1,
                      arr);
        }

        // Skip current element
        int skip =
            solve(p,
                  i + 1,
                  arr);

        int ans = max(take, skip);

        if(p != -1) {
            t[p][i] = ans;
        }

        return ans;
    }

    int maxSumIS(vector<int>& arr) {

        n = arr.size();

        memset(t, -1, sizeof(t));

        return solve(-1, 0, arr);
    }
};

/*
==========================
🔥 MAXIMUM SUM
INCREASING SUBSEQUENCE
==========================

Goal:
Find an increasing subsequence
with the maximum possible sum.

--------------------------------

🧠 Core Idea:

This is a weighted version of LIS.

Instead of maximizing length,
maximize the sum of selected
elements.

--------------------------------

State:

solve(prev, i)

prev = previously chosen index
i    = current index

Returns maximum achievable sum.

--------------------------------

Choices:

1. Take arr[i]
   if arr[i] > arr[prev]

2. Skip arr[i]

Answer =
max(take, skip)

--------------------------------

Base Case:

i == n
→ return 0

--------------------------------

Example:

arr = [1, 101, 2, 3, 100]

Best increasing subsequence:
1 → 2 → 3 → 100

Sum = 106

--------------------------------

⏱️ Time Complexity:
O(n²)

--------------------------------

🧠 Space Complexity:
O(n²)

+ recursion stack O(n)

--------------------------------

🧩 Pattern:
LIS Variant

--------------------------------

🎯 Category:
Dynamic Programming → Subsequences

--------------------------------

🧠 Interview One-Liner:

Same as LIS, but maximize total
sum instead of subsequence length.

*/

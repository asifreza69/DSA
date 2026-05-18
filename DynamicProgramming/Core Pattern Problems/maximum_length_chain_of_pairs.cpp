class Solution {
public:
    int n;
    int t[1001][1001];

    // p = index of previously selected pair
    // i = current pair under consideration
    int solve(int p,
              int i,
              vector<vector<int>>& arr) {

        // No more pairs
        if(i >= n) {
            return 0;
        }

        // Memoized result
        if(p != -1 && t[p][i] != -1) {
            return t[p][i];
        }

        int take = 0;

        /*
        We can take current pair if:
        previous.second < current.first
        */
        if(p == -1 ||
           arr[p][1] < arr[i][0]) {

            take =
                1 + solve(i,
                          i + 1,
                          arr);
        }

        // Skip current pair
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

    int maxChainLen(vector<vector<int>>& arr) {

        n = arr.size();

        memset(t, -1, sizeof(t));

        // Sort by first element
        sort(arr.begin(), arr.end());

        return solve(-1, 0, arr);
    }
};

/*
==========================
🔥 MAXIMUM LENGTH
CHAIN OF PAIRS
==========================

Goal:
Given pairs (a, b), find the
longest chain such that:

previous.second < current.first

--------------------------------

🧠 Core Idea:

This is a variation of LIS.

Instead of:
nums[j] < nums[i]

We use:
arr[j][1] < arr[i][0]

--------------------------------

State:

solve(prev, i)

prev = index of last chosen pair
i    = current index

Returns the maximum chain length
starting from i.

--------------------------------

Choices:

1. Take current pair
   if compatible with prev.

2. Skip current pair.

Answer =
max(take, skip)

--------------------------------

Base Case:

i == n
→ return 0

--------------------------------

Example:

Pairs:
(5,24), (15,25), (27,40), (50,60)

Longest chain:
(5,24) → (27,40) → (50,60)

Answer = 3

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

💡 Greedy Optimization:

Sort by second value and greedily
pick non-overlapping pairs.

Greedy Time: O(n log n)

--------------------------------

🧠 Interview One-Liner:

This is LIS on pairs where
pair A can follow pair B if
B.second < A.first.

*/

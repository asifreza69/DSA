class Solution {
public:
    int n;
    int t[1001][1001];

    int solve(int prev,
              int i,
              vector<int>& arr) {

        // Reached end of array
        if(i >= n) {
            return 0;
        }

        // Memoized result
        // prev = index of previous chosen element
        if(prev != -1 &&
           t[prev][i] != -1) {
            return t[prev][i];
        }

        int take = 0;

        // Can include current element
        if(prev == -1 ||
           arr[prev] < arr[i]) {

            take = 1 +
                   solve(i,
                         i + 1,
                         arr);
        }

        // Skip current element
        int skip =
            solve(prev,
                  i + 1,
                  arr);

        int ans = max(take, skip);

        if(prev != -1) {
            t[prev][i] = ans;
        }

        return ans;
    }

    int lis(vector<int>& arr) {

        n = arr.size();

        memset(t, -1, sizeof(t));

        return solve(-1, 0, arr);
    }
};

/*
==========================
🔥 LONGEST INCREASING
SUBSEQUENCE (LIS)
==========================

Goal:
Find the length of the longest
strictly increasing subsequence.

Subsequence does not need to be
contiguous.

--------------------------------

🧠 Core Idea:

For each element, decide:

1. Take it
   (only if greater than the
    previously chosen element)

2. Skip it

Take the maximum length.

--------------------------------

State:

solve(prev, i)

prev = index of previously
selected element (-1 if none)

i = current index

--------------------------------

Recurrence:

take =
1 + solve(i, i+1)
if prev == -1 or arr[prev] < arr[i]

skip =
solve(prev, i+1)

answer =
max(take, skip)

--------------------------------

Base Case:

i == n
→ return 0

--------------------------------

Example:

arr = [10, 9, 2, 5, 3, 7, 101, 18]

LIS = [2, 3, 7, 101]
Length = 4

--------------------------------

⏱️ Time Complexity:
O(n²)

--------------------------------

🧠 Space Complexity:
O(n²)

+ recursion stack O(n)

--------------------------------

🧩 Pattern:
Take / Skip DP

--------------------------------

🎯 Category:
Dynamic Programming → LIS Pattern

--------------------------------

🧠 Interview One-Liner:

At each index, either include the
element if it keeps the sequence
increasing or skip it, and take
the best result.


==========================
🔥 LONGEST INCREASING
SUBSEQUENCE (TABULATION)
==========================
*/
int lis(vector<int>& arr) {

    int n = arr.size();

    // dp[i] = length of LIS ending at index i
    vector<int> dp(n, 1);

    // Build answer
    for(int i = 0; i < n; i++) {

        for(int j = 0; j < i; j++) {

            // If current element can extend LIS ending at j
            if(arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // Maximum LIS among all ending positions
    return *max_element(dp.begin(), dp.end());
}

/*

State:

dp[i] =
Length of the longest increasing
subsequence that ends at index i.

--------------------------------

Transition:

For every previous index j < i:

If arr[i] > arr[j],
then arr[i] can extend the LIS
ending at j.

dp[i] =
max(dp[i], dp[j] + 1)

--------------------------------

Initialization:

dp[i] = 1

Because each element alone forms
an increasing subsequence of
length 1.

--------------------------------

Final Answer:

max(dp[i]) for all i

--------------------------------

Example:

arr = [10, 9, 2, 5, 3, 7, 101, 18]

dp = [1, 1, 1, 2, 2, 3, 4, 4]

Answer = 4

--------------------------------

⏱️ Time Complexity:
O(n²)

--------------------------------

🧠 Space Complexity:
O(n)

--------------------------------

🧩 Pattern:
LIS Dynamic Programming

--------------------------------

🎯 Category:
Dynamic Programming → LIS Pattern

--------------------------------

🧠 Interview One-Liner:

For each element, look at all
previous smaller elements and
extend the longest subsequence
ending there.

*/




class Solution {
public:
    int minSum(vector<int>& arr) {

        int n = arr.size();

        // If array size <= 4,
        // choose the minimum element.
        if(n <= 4) {
            return *min_element(arr.begin(), arr.end());
        }

        // dp[i] =
        // minimum sum if arr[i]
        // is selected.
        vector<int> dp(n, 0);

        // Base cases
        dp[0] = arr[0];
        dp[1] = arr[1];
        dp[2] = arr[2];
        dp[3] = arr[3];

        // Transition
        for(int i = 4; i < n; i++) {

            dp[i] = arr[i] +
                    min({
                        dp[i - 1],
                        dp[i - 2],
                        dp[i - 3],
                        dp[i - 4]
                    });
        }

        // Final answer can end at any of
        // the last four positions.
        return min({
            dp[n - 1],
            dp[n - 2],
            dp[n - 3],
            dp[n - 4]
        });
    }
};

/*
==========================
🔥 MINIMUM SUM
(At Least One Pick in Every
 Four Consecutive Elements)
==========================

Goal:
Select elements such that in
every group of 4 consecutive
elements, at least one element
is chosen.

Return the minimum possible sum.

--------------------------------

🧠 Core Idea:

Suppose we decide to select arr[i].

Then the previous selected
element must lie within:
i-1, i-2, i-3, or i-4.

If it were farther away,
there would exist 4 consecutive
elements with no selected item.

--------------------------------

State:

dp[i] =
Minimum sum when arr[i]
is selected.

--------------------------------

Transition:

dp[i] =
arr[i] +
min(
    dp[i-1],
    dp[i-2],
    dp[i-3],
    dp[i-4]
)

--------------------------------

Base Cases:

For i = 0 to 3:

dp[i] = arr[i]

Selecting any one of these
already satisfies all windows
ending there.

--------------------------------

Final Answer:

The last selected element
must be in the final four
positions.

Answer =
min(
    dp[n-1],
    dp[n-2],
    dp[n-3],
    dp[n-4]
)

--------------------------------

Example:

arr = [1, 2, 3, 4, 5]

Best choice:
Pick 1 and 5

Total = 6

--------------------------------

⏱️ Time Complexity:
O(n)

--------------------------------

🧠 Space Complexity:
O(n)

Can be optimized to O(1)
using only last four states.

--------------------------------

🧩 Pattern:
1D Dynamic Programming

--------------------------------

🎯 Category:
Dynamic Programming → Constraint DP

--------------------------------

🧠 Interview One-Liner:

If arr[i] is chosen, the previous
chosen element must be among the
last four positions, otherwise a
window of four elements would be
left uncovered.

*/

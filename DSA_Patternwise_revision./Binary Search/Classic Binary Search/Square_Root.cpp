/*
    Problem: Square Root
    Pattern: Classic Binary Search

    Approach:
    1. Search for the largest integer whose square is less than or equal to n.
    2. Initialize the search space from 1 to n/2.
    3. Compute the middle value and check if its square is <= n.
    4. If true, store it as a possible answer and search in the right half.
    5. Otherwise, search in the left half.
    6. Return the stored answer.

    Key Insight:
    The answer is the greatest integer x such that:

        x² ≤ n

    Binary Search efficiently finds this value without checking every integer.

    Time Complexity: O(log n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int floorSqrt(int n) {
        if (n == 0 || n == 1)
            return n;

        int i = 1, j = n / 2;
        int ans = 1;

        while (i <= j) {
            int mid = i + (j - i) / 2;

            // Use long long to avoid overflow
            if (1LL * mid * mid <= n) {
                ans = mid;
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }

        return ans;
    }
};

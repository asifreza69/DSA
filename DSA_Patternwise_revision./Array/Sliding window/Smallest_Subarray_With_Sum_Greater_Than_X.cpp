/*
    Problem: Smallest Subarray With Sum Greater Than X
    Pattern: Sliding Window (Variable Size)

    Approach:
    1. Maintain a sliding window using two pointers i and j.
    2. Expand the window by adding arr[j] to the current sum.
    3. Once the sum becomes greater than x:
       - Update the minimum window length.
       - Shrink the window from the left by removing arr[i].
       - Continue shrinking while the sum remains greater than x.
    4. Repeat until the entire array is traversed.
    5. If no valid subarray is found, return 0.

    Key Insight:
    Since all array elements are positive, increasing the window increases
    the sum, while shrinking the window decreases it. This allows us to
    find the minimum valid window in linear time.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        int sum = 0, ans = INT_MAX;
        int i = 0, j = 0;

        while (j < arr.size()) {
            sum += arr[j];

            while (sum > x) {
                ans = min(ans, j - i + 1);
                sum -= arr[i];
                i++;
            }

            j++;
        }

        return ans == INT_MAX ? 0 : ans;
    }
};

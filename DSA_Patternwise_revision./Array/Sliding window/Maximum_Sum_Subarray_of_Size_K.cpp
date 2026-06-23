


/*
    Problem: Maximum Sum Subarray of Size K
    Pattern: Sliding Window (Fixed Size)

    Approach:
    1. Maintain a window of size k using two pointers i and j.
    2. Expand the window by adding arr[j] to the current sum.
    3. Once the window size becomes k:
       - Update the answer with the maximum sum encountered.
       - Remove arr[i] from the current sum.
       - Slide the window forward by incrementing i.
    4. Continue until the entire array is traversed.

    Key Insight:
    Instead of recomputing the sum for every subarray of size k,
    maintain the sum of the current window and update it in O(1)
    while sliding the window.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int sum = 0;
        int ans = 0;
        int i = 0, j = 0;

        while (j < arr.size()) {
            sum += arr[j];

            if (j - i + 1 == k) {
                ans = max(ans, sum);
                sum -= arr[i];
                i++;
            }

            j++;
        }

        return ans;
    }
};


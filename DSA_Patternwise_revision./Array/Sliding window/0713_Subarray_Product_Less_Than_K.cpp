/*
    Problem: Subarray Product Less Than K
    Pattern: Sliding Window (Variable Size)

    Approach:
    1. If k <= 1, no valid subarray can exist since all elements are positive.
    2. Maintain a sliding window using two pointers i and j.
    3. Expand the window by multiplying nums[j] with the current product.
    4. While the product becomes greater than or equal to k:
       - Divide the product by nums[i].
       - Move the left pointer forward.
    5. Once the window becomes valid, all subarrays ending at j and starting
       from i to j are valid.
    6. Add (j - i + 1) to the answer and continue.

    Key Insight:
    Every valid sliding window contributes multiple valid subarrays.
    If the current window is valid, then every suffix of the window ending
    at j is also valid.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int countSubarray(vector<int>& arr, int k) {
        if (k <= 1) return 0;

        int i = 0, j = 0;
        int p = 1;
        int ans = 0;

        while (j < arr.size()) {
            p *= arr[j];

            while (p >= k) {
                p /= arr[i];
                i++;
            }

            ans += j - i + 1;
            j++;
        }

        return ans;
    }
};

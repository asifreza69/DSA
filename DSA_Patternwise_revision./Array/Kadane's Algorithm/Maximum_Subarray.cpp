/*
    Problem: Maximum Subarray
    Pattern: Kadane's Algorithm

    Approach:
    1. Maintain a running sum while traversing the array.
    2. Add the current element to the running sum.
    3. Update the maximum subarray sum encountered so far.
    4. If the running sum becomes negative, reset it to 0 since a negative
       sum cannot contribute to a larger subarray in the future.
    5. Continue until the entire array is processed.

    Key Insight:
    A negative running sum only decreases the sum of future subarrays.
    Therefore, whenever the running sum becomes negative, discard it and
    start a new subarray from the next element.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int maxSubarraySum(vector<int>& arr) {
        int maxi = INT_MIN;
        int sum = 0;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            maxi = max(maxi, sum);

            if (sum < 0) {
                sum = 0;
            }
        }

        return maxi;
    }
};

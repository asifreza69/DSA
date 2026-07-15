/*
    Problem: Maximum Sum Circular Subarray
    Pattern: Kadane's Algorithm

    Approach:
    1. Compute the maximum subarray sum using Kadane's Algorithm.
    2. Compute the minimum subarray sum using a modified Kadane's Algorithm.
    3. Calculate the total sum of the array.
    4. The maximum circular subarray sum is:
           Total Sum - Minimum Subarray Sum
       since removing the minimum subarray leaves the maximum circular subarray.
    5. If all elements are negative, return the normal maximum subarray sum
       because the circular sum would incorrectly become 0.
    6. Otherwise, return the maximum of the normal and circular subarray sums.

    Key Insight:
    There are two possible answers:
    - A normal (non-circular) maximum subarray.
    - A circular maximum subarray obtained by excluding the minimum subarray.

        Circular Sum = Total Sum - Minimum Subarray Sum

    The edge case occurs when every element is negative. In that case,
    the circular sum is invalid, so the normal Kadane's result is returned.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int maximumsum(vector<int>& nums) {
        int maxi = nums[0];
        int sum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            sum = max(sum + nums[i], nums[i]);
            maxi = max(maxi, sum);
        }

        return maxi;
    }

    int minisum(vector<int>& nums) {
        int mini = nums[0];
        int sum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            sum = min(sum + nums[i], nums[i]);
            mini = min(mini, sum);
        }

        return mini;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        int maxsum = maximumsum(nums);
        int minsum = minisum(nums);

        int circularsum = sum - minsum;

        if (maxsum > 0) {
            return max(maxsum, circularsum);
        }

        return maxsum;
    }
};

/*
    Problem: Maximum Absolute Sum of Any Subarray
    Pattern: Kadane's Algorithm

    Approach:
    1. Use Kadane's Algorithm to find the maximum subarray sum.
    2. Use a modified Kadane's Algorithm to find the minimum subarray sum.
    3. The answer is the larger of:
       - Absolute value of the maximum subarray sum.
       - Absolute value of the minimum subarray sum.
    4. Return the maximum absolute value.

    Key Insight:
    The maximum absolute subarray sum can arise from:
    - A large positive subarray sum.
    - A large negative subarray sum.

    Therefore,

        Answer = max(|Maximum Subarray Sum|,
                     |Minimum Subarray Sum|)

    Computing both using Kadane's Algorithm gives the result in linear time.

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

    int maxAbsoluteSum(vector<int>& nums) {
        int maxsum = maximumsum(nums);
        int minsum = minisum(nums);

        return max(abs(maxsum), abs(minsum));
    }
};

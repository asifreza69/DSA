/*
    Problem: Maximum Sum of Distinct Subarrays With Length K
    Pattern: Sliding Window + Hash Map

    Approach:
    1. Maintain a sliding window using two pointers i and j.
    2. Use a hash map to store the frequency of elements inside the current window.
    3. Expand the window by adding nums[j] and updating the running sum.
    4. If duplicates exist, shrink the window from the left until all elements become distinct.
    5. Whenever the window size becomes k and contains exactly k distinct elements:
       - Update the answer with the maximum sum.
       - Slide the window by removing the leftmost element.
    6. Continue until the entire array is traversed.

    Key Insight:
    A valid subarray must satisfy two conditions:
    - Window size = k.
    - Number of distinct elements = k.
    Using a hash map allows efficient detection and removal of duplicates while
    maintaining the sum of the current window.

    Time Complexity: O(n)
    Space Complexity: O(k)
*/

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        long long sum = 0;
        long long ans = 0;
        int i = 0, j = 0;

        while (j < nums.size()) {
            mp[nums[j]]++;
            sum += nums[j];

            if (mp.size() == k && j - i + 1 == k) {
                ans = max(ans, sum);
                sum -= nums[i];
                mp.erase(nums[i]);
                i++;
            }

            while (j - i + 1 > mp.size()) {
                sum -= nums[i];
                mp[nums[i]]--;

                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);

                i++;
            }

            j++;
        }

        return ans;
    }
};

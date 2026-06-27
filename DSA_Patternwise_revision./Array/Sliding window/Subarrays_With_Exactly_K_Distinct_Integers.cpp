/*
    Problem: Subarrays With Exactly K Distinct Integers
    Pattern: Sliding Window + Hash Map

    Approach:
    1. Define a helper function to count subarrays with at most k distinct elements.
    2. Maintain a sliding window using two pointers i and j.
    3. Use a hash map to store the frequency of elements in the current window.
    4. Expand the window by including arr[j].
    5. If the number of distinct elements exceeds k:
       - Shrink the window from the left.
       - Decrease the frequency of arr[i].
       - Remove it from the map when its frequency becomes zero.
    6. For every valid window, add (j - i + 1) to the answer since all
       subarrays ending at j are valid.
    7. The required answer is:
           AtMost(k) - AtMost(k - 1)

    Key Insight:
    Counting subarrays with exactly k distinct elements directly is difficult.
    Instead, compute:
        Exactly(k) = AtMost(k) - AtMost(k - 1)
    This converts the problem into two standard sliding window problems.

    Time Complexity: O(n)
    Space Complexity: O(k)
*/

class Solution {
public:
    int solve(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        int i = 0, j = 0, ans = 0;

        while (j < arr.size()) {
            mp[arr[j]]++;

            while (mp.size() > k) {
                mp[arr[i]]--;

                if (mp[arr[i]] == 0) {
                    mp.erase(arr[i]);
                }

                i++;
            }

            ans += j - i + 1;
            j++;
        }

        return ans;
    }

    int exactlyK(vector<int>& arr, int k) {
        return solve(arr, k) - solve(arr, k - 1);
    }
};

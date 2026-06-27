/*
    Problem: Fruit Into Baskets
    Pattern: Sliding Window (Variable Size)

    Approach:
    1. Maintain a sliding window using two pointers i and j.
    2. Use a hash map to store the frequency of each fruit type in the current window.
    3. Expand the window by including arr[j].
    4. If the number of distinct fruit types exceeds two:
       - Shrink the window from the left.
       - Decrease the frequency of arr[i].
       - Remove it from the map if its frequency becomes zero.
    5. Once the window contains at most two distinct fruit types,
       update the maximum window size.
    6. Continue until the entire array is traversed.

    Key Insight:
    The window is valid only when it contains at most two distinct elements.
    Whenever a third distinct element appears, shrink the window until it
    becomes valid again.

    Time Complexity: O(n)
    Space Complexity: O(2) ≈ O(1)
*/

class Solution {
public:
    int totalElements(vector<int>& arr) {
        unordered_map<int, int> mp;
        int i = 0, j = 0, ans = 0;

        while (j < arr.size()) {
            mp[arr[j]]++;

            while (mp.size() > 2) {
                mp[arr[i]]--;

                if (mp[arr[i]] == 0) {
                    mp.erase(arr[i]);
                }

                i++;
            }

            ans = max(ans, j - i + 1);
            j++;
        }

        return ans;
    }
};

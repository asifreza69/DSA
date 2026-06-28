/*
    Problem: Subarray Sum Equals K
    Pattern: Prefix Sum + Hash Map

    Approach:
    1. Maintain a running prefix sum while traversing the array.
    2. At every index, check if the current prefix sum itself equals k.
       If yes, increment the answer.
    3. Calculate (prefixSum - k).
       - If this value has appeared before, then every occurrence represents
         a valid starting point of a subarray whose sum equals k.
    4. Add the frequency of (prefixSum - k) to the answer.
    5. Store the current prefix sum in the hash map for future lookups.

    Key Insight:
    Let the current prefix sum be S.
    If there exists a previous prefix sum (S - k), then the subarray between
    those two indices has a sum equal to k.

        Subarray Sum = Current Prefix Sum - Previous Prefix Sum
                     = S - (S - k)
                     = k

    The hash map stores the frequency of every prefix sum, allowing us to
    count all valid subarrays in a single traversal.

    Time Complexity: O(n)
    Space Complexity: O(n)
*/

class Solution {
public:
    int cntSubarrays(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        int sum = 0;
        int ans = 0;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            if (sum == k) {
                ans++;
            }

            if (mp.find(sum - k) != mp.end()) {
                ans += mp[sum - k];
            }

            mp[sum]++;
        }

        return ans;
    }
};

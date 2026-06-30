/*
    Problem: Subarray Sums Divisible By K
    Pattern: Prefix Sum + Hash Map

    Approach:
    1. Maintain a running prefix sum while traversing the array.
    2. Compute the remainder of the prefix sum when divided by k.
    3. If the remainder is negative, normalize it by adding k.
    4. Use a hash map to store the frequency of each remainder.
    5. If the current remainder has appeared before:
       - Every previous occurrence forms a subarray whose sum is divisible by k.
       - Add its frequency to the answer.
    6. Increment the frequency of the current remainder.

    Key Insight:
    Let PrefixSum(i) % k = r and PrefixSum(j) % k = r.

    Then,

        (PrefixSum(j) - PrefixSum(i)) % k = 0

    which means the subarray between i+1 and j has a sum divisible by k.

    The hash map stores the frequency of each remainder, allowing us to
    count all valid subarrays in a single traversal.

    Time Complexity: O(n)
    Space Complexity: O(k)
*/

class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        long long sum = 0, ans = 0;

        mp[0] = 1;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            int rem = sum % k;
            if (rem < 0)
                rem += k;

            if (mp.find(rem) != mp.end()) {
                ans += mp[rem];
            }

            mp[rem]++;
        }

        return ans;
    }
};

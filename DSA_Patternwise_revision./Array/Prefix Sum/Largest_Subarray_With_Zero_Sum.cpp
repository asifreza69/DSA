/*
    Problem: Largest Subarray With Zero Sum
    Pattern: Prefix Sum + Hash Map

    Approach:
    1. Maintain a running prefix sum while traversing the array.
    2. If the prefix sum becomes 0, the subarray from index 0 to the current
       index has a sum of zero.
    3. Store the first occurrence of every prefix sum in a hash map.
    4. If the same prefix sum appears again:
       - The elements between the previous occurrence and the current index
         form a subarray with sum equal to zero.
       - Update the maximum length accordingly.
    5. Continue until the entire array is traversed.

    Key Insight:
    If two prefix sums are equal, then the sum of the elements between
    those indices is zero.

        PrefixSum(j) - PrefixSum(i) = 0
        ⇒ PrefixSum(j) = PrefixSum(i)

    Storing only the first occurrence of each prefix sum ensures that we
    obtain the longest possible zero-sum subarray.

    Time Complexity: O(n)
    Space Complexity: O(n)
*/

class Solution {
public:
    int maxLength(vector<int>& arr) {
        int sum = 0, ans = 0;
        unordered_map<int, int> mp;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            if (sum == 0) {
                ans = max(ans, i + 1);
            }
            else if (mp.find(sum) != mp.end()) {
                ans = max(ans, i - mp[sum]);
            }
            else {
                mp[sum] = i;
            }
        }

        return ans;
    }
};

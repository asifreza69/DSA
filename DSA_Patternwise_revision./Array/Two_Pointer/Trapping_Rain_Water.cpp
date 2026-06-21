/*
    Problem: Trapping Rain Water
    Pattern: Prefix Maximum / Suffix Maximum

    Approach:
    1. Create two arrays:
       - leftMax[i] stores the maximum height to the left of index i.
       - rightMax[i] stores the maximum height to the right of index i.
    2. Traverse from left to right to fill leftMax.
    3. Traverse from right to left to fill rightMax.
    4. For each index i, the water trapped is:
            min(leftMax[i], rightMax[i]) - arr[i]
    5. Sum the trapped water at all indices.

    Key Insight:
    The amount of water that can be stored above a bar depends on the
    minimum of the tallest bars on its left and right sides.

    Time Complexity: O(n)
    Space Complexity: O(n)
*/

class Solution {
public:
    int maxWater(vector<int>& arr) {
        vector<int> leftMax(arr.size(), 0);
        vector<int> rightMax(arr.size(), 0);

        int maxi = 0;
        for (int i = 0; i < arr.size(); i++) {
            maxi = max(maxi, arr[i]);
            leftMax[i] = maxi;
        }

        maxi = 0;
        for (int i = arr.size() - 1; i >= 0; i--) {
            maxi = max(maxi, arr[i]);
            rightMax[i] = maxi;
        }

        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            ans += min(leftMax[i], rightMax[i]) - arr[i];
        }

        return ans;
    }
};


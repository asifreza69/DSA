/*
    Problem: Search Insert Position
    Pattern: Classic Binary Search

    Approach:
    1. Use lower_bound() to find the first element that is greater than or
       equal to the target.
    2. If the target exists, lower_bound() returns its index.
    3. If the target does not exist, it returns the position where the target
       should be inserted to maintain the sorted order.
    4. Return the obtained index.

    Key Insight:
    lower_bound() always returns the first position where the target can be
    placed without violating the sorted order, making it ideal for finding
    the search or insertion position.

    * Use upper_bound() to find the first element that is strictly greater
    than the target.

    Time Complexity: O(log n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int searchInsertK(vector<int>& arr, int k) {
        int t = lower_bound(arr.begin(), arr.end(), k) - arr.begin();
        return t;
    }
};

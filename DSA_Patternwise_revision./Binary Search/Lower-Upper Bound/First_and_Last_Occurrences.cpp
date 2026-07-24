/*
    Problem: First and Last Occurrences
    Pattern: Lower Bound / Upper Bound

    Approach:
    1. Use lower_bound() to find the first occurrence of the target.
    2. Use upper_bound() to find the position just after the last occurrence.
    3. If lower_bound() points outside the array or the element at that index
       is not the target, the target does not exist.
    4. Otherwise:
       - First Occurrence = lower_bound
       - Last Occurrence = upper_bound - 1
    5. Return both indices.

    Key Insight:
    In a sorted array:
    - lower_bound(target) gives the first occurrence.
    - upper_bound(target) gives the index after the last occurrence.

    Therefore,

        First Occurrence = lower_bound(target)
        Last Occurrence  = upper_bound(target) - 1

    Time Complexity: O(log n)
    Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> find(vector<int>& arr, int x) {
        int l = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int h = upper_bound(arr.begin(), arr.end(), x) - arr.begin();

        if (l == arr.size() || arr[l] != x) {
            return {-1, -1};
        }

        return {l, h - 1};
    }
};

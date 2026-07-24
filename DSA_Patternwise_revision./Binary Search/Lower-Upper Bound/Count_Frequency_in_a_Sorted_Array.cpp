/*
    Problem: Count Frequency in a Sorted Array
    Pattern: Lower Bound / Upper Bound

    Approach:
    1. Find the first occurrence of the target using lower_bound().
    2. Find the position just after the last occurrence using upper_bound().
    3. The difference between these two positions gives the total frequency.
    4. If the target does not exist, both iterators point to the same position,
       resulting in a frequency of 0.

    Key Insight:
    In a sorted array:
    - lower_bound(target) returns the first index where element >= target.
    - upper_bound(target) returns the first index where element > target.

    Therefore,

        Frequency = upper_bound(target) - lower_bound(target)

    Time Complexity: O(log n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int countFreq(vector<int>& arr, int target) {
        return upper_bound(arr.begin(), arr.end(), target) -
               lower_bound(arr.begin(), arr.end(), target);
    }
};

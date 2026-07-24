/*
    Problem: Ceil in a Sorted Array
    Pattern: Lower Bound / Upper Bound

    Approach:
    1. Use lower_bound() to find the first element that is greater than or
       equal to the target x.
    2. If lower_bound() returns arr.end(), then no ceiling exists, so return -1.
    3. Otherwise, return the index of the ceiling element.

    Key Insight:
    The ceiling of x is the smallest element in the sorted array that is
    greater than or equal to x.

    Since lower_bound() returns the first position where:

        arr[index] >= x

    it directly gives the index of the ceiling element.

    Time Complexity: O(log n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int findCeil(vector<int>& arr, int x) {
        int t = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

        if (t == arr.size()) {
            return -1;
        }

        return t;
    }
};

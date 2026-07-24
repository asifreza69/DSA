/*
    Problem: Floor in a Sorted Array
    Pattern: Lower Bound / Upper Bound

    Approach:
    1. Use upper_bound() to find the first element that is strictly greater
       than the target x.
    2. If upper_bound() returns the beginning of the array, then no floor
       exists, so return -1.
    3. Otherwise, the previous index (upper_bound - 1) is the floor.
    4. Return the index of the floor element.

    Key Insight:
    The floor of x is the largest element in the sorted array that is
    less than or equal to x.

    Since upper_bound() returns the first position where:

        arr[index] > x

    the previous position gives the floor element.

    Time Complexity: O(log n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int findFloor(vector<int>& arr, int x) {
        int t = upper_bound(arr.begin(), arr.end(), x) - arr.begin();

        if (t == 0) {
            return -1;
        }

        return t - 1;
    }
};

/*
    Problem: Minimum in Sorted and Rotated Array
    Pattern: Modified Binary Search

    Approach:
    1. If the current search space is already sorted, the first element is
       the minimum.
    2. Find the middle element.
    3. If the middle element is smaller than its previous element, it is
       the minimum.
    4. If the middle element is greater than its next element, then the next
       element is the minimum.
    5. Otherwise, determine which half is sorted.
       - If the left half is sorted, search in the right half.
       - Else, search in the left half.
    6. Repeat until the minimum element is found.

    Key Insight:
    In a rotated sorted array, one half is always sorted.
    The minimum element lies in the unsorted half unless the current search
    space itself is already sorted.

    Time Complexity: O(log n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int findMin(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;
        int n = arr.size();

        while (low <= high) {

            // Array is already sorted
            if (arr[low] <= arr[high])
                return arr[low];

            int mid = low + (high - low) / 2;

            // Pivot found
            if (mid > 0 && arr[mid] < arr[mid - 1])
                return arr[mid];

            if (mid < n - 1 && arr[mid] > arr[mid + 1])
                return arr[mid + 1];

            // Left half is sorted
            if (arr[mid] >= arr[low])
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }
};

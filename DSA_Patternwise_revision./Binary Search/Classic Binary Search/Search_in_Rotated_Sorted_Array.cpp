/*
    Problem: Search in Rotated Sorted Array
    Pattern: Modified Binary Search

    Approach:
    1. Apply Binary Search on the rotated sorted array.
    2. If the middle element is the target, return its index.
    3. Determine which half of the array is sorted.
    4. If the left half is sorted:
       - Check whether the target lies within this range.
       - If yes, search the left half; otherwise, search the right half.
    5. If the right half is sorted:
       - Check whether the target lies within this range.
       - If yes, search the right half; otherwise, search the left half.
    6. Repeat until the target is found or the search space becomes empty.

    Key Insight:
    In a rotated sorted array, at least one half is always sorted.
    By identifying the sorted half and checking whether the target lies
    within its range, half of the search space can be discarded in every
    iteration.

    Time Complexity: O(log n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int search(vector<int>& arr, int key) {
        int low = 0, high = arr.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == key) {
                return mid;
            }

            // Left half is sorted
            else if (arr[low] <= arr[mid]) {
                if (key >= arr[low] && key < arr[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            // Right half is sorted
            else {
                if (key > arr[mid] && key <= arr[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};

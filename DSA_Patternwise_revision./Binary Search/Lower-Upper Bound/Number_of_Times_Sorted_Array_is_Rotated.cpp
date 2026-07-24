/*
    Problem: Number of Times Sorted Array is Rotated
    Pattern: Modified Binary Search

    Approach:
    1. Observe that the number of rotations equals the index of the minimum element.
    2. Apply Binary Search on the rotated sorted array.
    3. Compare the middle element with the last element.
    4. If arr[mid] < arr[high], the minimum lies in the left half
       (including mid), so move high to mid.
    5. Otherwise, the minimum lies in the right half, so move low to mid + 1.
    6. When both pointers meet, the index points to the minimum element,
       which is also the number of rotations.

    Key Insight:
    In a sorted and rotated array, the minimum element represents the pivot.
    Its index is exactly the number of clockwise rotations performed on the
    original sorted array.

    Time Complexity: O(log n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int findKRotation(vector<int>& arr) {
        int l = 0, h = arr.size() - 1;

        while (l < h) {
            int m = l + (h - l) / 2;

            if (arr[m] < arr[h]) {
                h = m;
            } else {
                l = m + 1;
            }
        }

        return l;
    }
};

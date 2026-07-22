/*
    Problem: Peak Element
    Pattern: Modified Binary Search

    Approach:
    1. Apply Binary Search on the array.
    2. Compare the middle element with its next element.
    3. If arr[mid] < arr[mid + 1], then a peak must exist in the right half,
       so move the left pointer to mid + 1.
    4. Otherwise, a peak lies in the left half (including mid), so move the
       right pointer to mid.
    5. Continue until both pointers meet.
    6. The meeting point is the index of a peak element.

    Key Insight:
    If the sequence is increasing at mid, a peak must exist on the right.
    Otherwise, the current element or some element on the left is guaranteed
    to be a peak. Binary Search narrows the search space to one peak.

    Time Complexity: O(log n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int peakElement(vector<int>& arr) {
        int l = 0, h = arr.size() - 1;

        while (l < h) {
            int m = l + (h - l) / 2;

            if (m + 1 < arr.size() && arr[m] < arr[m + 1]) {
                l = m + 1;
            } else {
                h = m;
            }
        }

        return h;
    }
};

/*
    Problem: Sort 0s, 1s and 2s
    Pattern: Two Pointers (Dutch National Flag Algorithm)

    Approach:
    1. Maintain three pointers:
       - low: boundary for 0s.
       - mid: current element being processed.
       - high: boundary for 2s.
    2. Traverse the array while mid <= high.
    3. If arr[mid] is 0:
       - Swap arr[mid] with arr[low].
       - Increment both low and mid.
    4. If arr[mid] is 1:
       - It is already in the correct position.
       - Increment mid.
    5. If arr[mid] is 2:
       - Swap arr[mid] with arr[high].
       - Decrement high.
       - Do not increment mid because the swapped element needs processing.
    6. Continue until all elements are placed in their correct regions.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    void sort012(vector<int>& arr) {
        int low = 0, mid = 0, high = arr.size() - 1;

        while (mid <= high) {
            if (arr[mid] == 0) {
                swap(arr[mid], arr[low]);
                low++;
                mid++;
            }
            else if (arr[mid] == 1) {
                mid++;
            }
            else {
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};


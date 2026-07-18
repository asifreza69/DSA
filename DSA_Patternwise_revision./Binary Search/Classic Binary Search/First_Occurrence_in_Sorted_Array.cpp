/*
    Problem: First Occurrence in Sorted Array
    Pattern: Classic Binary Search

    Approach:
    1. Apply Binary Search on the sorted array.
    2. If the middle element equals the target, store its index as a potential answer.
    3. Continue searching in the left half to find an earlier occurrence.
    4. If the middle element is greater than the target, move to the left half.
    5. Otherwise, search in the right half.
    6. Return the stored index, or -1 if the target is not found.

    Key Insight:
    Once the target is found, do not stop immediately.
    Continue searching on the left side because there may be another
    occurrence before the current one.

    Time Complexity: O(log n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int firstSearch(vector<int>& arr, int k) {
        int i = 0, j = arr.size() - 1;
        int ans = -1;

        while (i <= j) {
            int mid = i + (j - i) / 2;

            if (arr[mid] == k) {
                ans = mid;
                j = mid - 1;
            }
            else if (arr[mid] > k) {
                j = mid - 1;
            }
            else {
                i = mid + 1;
            }
        }

        return ans;
    }
};

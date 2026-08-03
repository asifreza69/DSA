/*
    Problem: Search in a Row and Column Wise Sorted Matrix
    Pattern: Search in 2D Matrix (Staircase Search)

    Approach:
    1. Start from the top-right corner of the matrix.
    2. Compare the current element with the target.
    3. If the current element equals the target, return true.
    4. If the current element is greater than the target:
       - Move left since all elements below are even larger.
    5. If the current element is smaller than the target:
       - Move down since all elements to the left are even smaller.
    6. Continue until the target is found or the search goes out of bounds.

    Key Insight:
    In a matrix where every row and every column is sorted:
    - Moving left decreases the value.
    - Moving down increases the value.

    Thus, every comparison eliminates an entire row or an entire column,
    resulting in an efficient search.

    Time Complexity: O(m + n)
    Space Complexity: O(1)
*/

class Solution {
public:
    bool matSearch(vector<vector<int>>& arr, int x) {
        int m = arr.size();
        int n = arr[0].size();

        int row = 0;
        int col = n - 1;

        while (row < m && col >= 0) {
            if (arr[row][col] == x)
                return true;
            else if (arr[row][col] > x)
                col--;
            else
                row++;
        }

        return false;
    }
};

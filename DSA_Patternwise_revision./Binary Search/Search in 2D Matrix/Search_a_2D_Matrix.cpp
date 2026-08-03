/*
    Problem: Search a 2D Matrix
    Pattern: Search in 2D Matrix (Flattened Binary Search)

    Approach:
    1. Treat the matrix as a virtual sorted 1D array.
    2. Apply Binary Search on the index range [0, rows × columns - 1].
    3. Convert the middle index into matrix coordinates:
       - row = mid / columns
       - col = mid % columns
    4. Compare matrix[row][col] with the target.
       - If equal, return true.
       - If smaller, search the right half.
       - Otherwise, search the left half.
    5. If the search space becomes empty, return false.

    Key Insight:
    Since the matrix is globally sorted, it behaves like a single sorted
    array. Using index conversion allows Binary Search without physically
    flattening the matrix.

    Time Complexity: O(log(m × n))
    Space Complexity: O(1)
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int l = 0;
        int h = rows * cols - 1;

        while (l <= h) {
            int m = l + (h - l) / 2;

            int r = m / cols;
            int c = m % cols;

            if (matrix[r][c] == target) {
                return true;
            }
            else if (matrix[r][c] < target) {
                l = m + 1;
            }
            else {
                h = m - 1;
            }
        }

        return false;
    }
};

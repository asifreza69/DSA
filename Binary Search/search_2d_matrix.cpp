#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int low = 0, high = m * n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int row = mid / n;   
            int col = mid % n;

            if (matrix[row][col] == target) {
                return true;
            }
            else if (matrix[row][col] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return false;
    }
};

/*
Problem: Search a 2D Matrix (LC 74)

Approach:
Binary Search (treat 2D as 1D)

Time Complexity: O(log(m*n))
Space Complexity: O(1)

Key Insight:
Map 1D index → 2D coordinates
*/

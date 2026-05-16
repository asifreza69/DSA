class Solution {
public:
    int maximumPath(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        // Allowed moves:
        // down-left, down, down-right
        vector<vector<int>> dir = {
            {1, -1},
            {1,  0},
            {1,  1}
        };

        // Start from second last row
        // and build answer upward.
        for(int i = m - 2; i >= 0; i--) {

            for(int j = 0; j < n; j++) {

                int maxi = mat[i][j];

                // Try all valid downward moves
                for(auto& d : dir) {

                    int x = i + d[0];
                    int y = j + d[1];

                    if(x >= 0 && x < m &&
                       y >= 0 && y < n) {

                        maxi = max(maxi,
                                   mat[i][j] + mat[x][y]);
                    }
                }

                // Store best path sum starting from (i,j)
                mat[i][j] = maxi;
            }
        }

        // Best path can start from any cell
        // in the first row.
        return *max_element(mat[0].begin(),
                            mat[0].end());
    }
};

/*
==========================
🔥 PATH IN MATRIX
==========================

Goal:
Find the maximum path sum from
top row to bottom row.

Allowed moves:
1. Down-left
2. Down
3. Down-right

--------------------------------

🧠 Core Idea:

Let dp[i][j] represent the maximum
path sum starting from cell (i, j).

Since each state depends on the
row below, process the matrix
from bottom to top.

--------------------------------

State:

dp[i][j] =
mat[i][j] +
max(
    dp[i+1][j-1],
    dp[i+1][j],
    dp[i+1][j+1]
)

--------------------------------

Base Case:

Last row:
dp[lastRow][j] = mat[lastRow][j]

--------------------------------

Final Answer:

max(dp[0][j])
for all columns j

--------------------------------

Example:

Matrix:
10 10  2  0 20  4
 1  0  0 30  2  5
 0 10  4  0  2  0
 1  0  2 20  0  4

Answer = 74

--------------------------------

⏱️ Time Complexity:
O(m × n)

Each cell checks 3 directions.

--------------------------------

🧠 Space Complexity:
O(1)

In-place modification of matrix.

--------------------------------

🧩 Pattern:
Grid Dynamic Programming

--------------------------------

🎯 Category:
Dynamic Programming → Matrix DP

--------------------------------

🧠 Interview One-Liner:

Process the matrix from bottom
to top, and for each cell add
the best among its three possible
downward moves.

*/

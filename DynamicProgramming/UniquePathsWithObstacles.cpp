// LeetCode 63: Unique Paths II
//
// Approach: Bottom-Up Dynamic Programming
//
// Idea:
// - Similar to Unique Paths but some cells contain obstacles.
// - If a cell has obstacle (grid[i][j] == 1), the robot cannot pass through it.
//
// - Let dp[i][j] represent number of ways to reach cell (i,j).
//
// - Base initialization for first row and first column
//   because robot can only come from one direction.
//
// - Recurrence:
//      if obstacle → dp[i][j] = 0
//      else → dp[i][j] = dp[i-1][j] + dp[i][j-1]
//
// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        // If start or end cell has obstacle
        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) {
            return 0;
        }

        vector<vector<int>> ans(m, vector<int>(n));

        // Initialize first column
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1) {
                ans[i][0] = 0;
            }
            else if (i - 1 >= 0 && ans[i - 1][0] == 0) {
                ans[i][0] = 0;
            }
            else {
                ans[i][0] = 1;
            }
        }

        // Initialize first row
        for (int i = 0; i < n; i++) {
            if (grid[0][i] == 1) {
                ans[0][i] = 0;
            }
            else if (i - 1 >= 0 && ans[0][i - 1] == 0) {
                ans[0][i] = 0;
            }
            else {
                ans[0][i] = 1;
            }
        }

        // Fill remaining grid
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {

                if (grid[i][j] == 1) {
                    ans[i][j] = 0;
                    continue;
                }

                ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
            }
        }

        return ans[m - 1][n - 1];
    }
};

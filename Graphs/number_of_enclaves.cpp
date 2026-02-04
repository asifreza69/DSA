// LeetCode 1020: Number of Enclaves
// Approach:
// Use DFS to eliminate all land cells connected to the boundary.
// Any land cell that can reach the boundary is NOT an enclave.
// After removing all boundary-connected land,
// count the remaining land cells.
//
// Time Complexity:
// O(m * n) — each cell is visited at most once.
//
// Space Complexity:
// O(m * n) — recursion stack in worst case.

class Solution {
public:
    // Direction vectors: down, right, up, left
    vector<vector<int>> dir{{1,0},{0,1},{-1,0},{0,-1}};

    // DFS to remove land connected to the boundary
    void dfs(int i, int j, vector<vector<int>>& grid) {

        // Out of bounds or water
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
            grid[i][j] == 0) {
            return;
        }

        // Mark current land as water (visited)
        grid[i][j] = 0;

        // Explore all four directions
        for (auto& d : dir) {
            dfs(i + d[0], j + d[1], grid);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        // Remove land connected to left and right boundaries
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1) {
                dfs(i, 0, grid);
            }
            if (grid[i][n - 1] == 1) {
                dfs(i, n - 1, grid);
            }
        }

        // Remove land connected to top and bottom boundaries
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1) {
                dfs(0, j, grid);
            }
            if (grid[m - 1][j] == 1) {
                dfs(m - 1, j, grid);
            }
        }

        // Count remaining land cells (enclaves)
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    count++;
                }
            }
        }

        return count;
    }
};

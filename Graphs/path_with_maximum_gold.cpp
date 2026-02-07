// LeetCode 1219: Path with Maximum Gold
// Approach:
// Use DFS + Backtracking to explore all possible paths.
//
// Rules handled:
// - We can move in 4 directions (up, down, left, right).
// - We cannot visit a cell more than once in a single path.
// - We stop DFS when we go out of bounds or hit a cell with 0 gold.
//
// Steps:
// 1. Start DFS from every non-zero cell.
// 2. Mark the current cell as visited by setting it to 0.
// 3. Explore all 4 directions and take the maximum gold collected.
// 4. Backtrack by restoring the original cell value.
//
// Time Complexity:
// O((m * n) * 4^(m*n)) in worst case (all cells have gold).
//
// Space Complexity:
// O(m * n) due to recursion stack.

class Solution {
public:
    int m;
    int n;

    // Directions: down, right, up, left
    vector<vector<int>> dir{{1,0},{0,1},{-1,0},{0,-1}};

    int dfs(int i, int j, vector<vector<int>>& grid) {

        // Boundary and invalid checks
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0) {
            return 0;
        }

        int original = grid[i][j];
        int maxGold = 0;

        // Mark current cell as visited
        grid[i][j] = 0;

        // Explore all directions
        for (auto& it : dir) {
            int x = i + it[0];
            int y = j + it[1];
            maxGold = max(maxGold, dfs(x, y, grid));
        }

        // Backtrack: restore original value
        grid[i][j] = original;

        return maxGold + original;
    }

    int getMaximumGold(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();
        int maxi = 0;

        // Try DFS from every cell containing gold
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    maxi = max(maxi, dfs(i, j, grid));
                }
            }
        }

        return maxi;
    }
};

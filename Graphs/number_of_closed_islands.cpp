class Solution {
public:
    int m = 0;
    int n = 0;

    // Direction vectors: down, right, up, left
    vector<vector<int>> dir{{1,0},{0,1},{-1,0},{0,-1}};

    // DFS to check whether the island is closed
    bool dfs(int i, int j, vector<vector<int>>& grid) {

        // If we go out of bounds, island touches boundary
        if (i < 0 || j < 0 || i >= m || j >= n) {
            return false;
        }

        // If already water or visited
        if (grid[i][j] == 1) {
            return true;
        }

        bool isClosed = true;

        // Mark current cell as visited
        grid[i][j] = 1;

        // Explore all four directions
        for (auto& d : dir) {
            int x_ = i + d[0];
            int y_ = j + d[1];

            // If any direction is not closed, island is not closed
            if (!dfs(x_, y_, grid)) {
                isClosed = false;
            }
        }

        return isClosed;
    }

    int closedIsland(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();
        int count = 0;

        // Only start DFS from inner cells
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 0 && dfs(i, j, grid)) {
                    count++;
                }
            }
        }

        return count;
    }
};

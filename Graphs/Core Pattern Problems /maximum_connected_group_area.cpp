class Solution {
public:

    int count = 0;
    int m, n;

    // 8 directions
    vector<vector<int>> dir = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1},
        {-1, -1}, {1, 1}, {1, -1}, {-1, 1}
    };

    void dfs(int i, int j, vector<vector<int>>& grid) {

        // mark visited
        grid[i][j] = 0;

        count++;

        for(auto &it : dir) {

            int x = i + it[0];
            int y = j + it[1];

            if(x >= 0 && x < m &&
               y >= 0 && y < n &&
               grid[x][y] == 1) {

                dfs(x, y, grid);
            }
        }
    }

    int findMaxArea(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        int maxi = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1) {

                    count = 0;

                    dfs(i, j, grid);

                    maxi = max(maxi, count);
                }
            }
        }

        return maxi;
    }
};

/*
==========================
🔥 MAXIMUM CONNECTED AREA
==========================

Goal:
Find the size of the largest
connected group of 1's.

--------------------------------

🧠 Core Idea:

Each group of connected 1's
forms one connected component.

Run DFS from every unvisited 1
and count its size.

Track the maximum size.

--------------------------------

Connectivity:
8 directions allowed:
- up, down, left, right
- 4 diagonals

--------------------------------

Algorithm:

1. Traverse all cells.
2. If cell == 1:
      count = 0
      DFS
      maxi = max(maxi, count)
3. Return maxi.

--------------------------------

Example:

1 1 0
0 1 0
1 0 1

Largest connected component size = 4
(diagonal connections included)

--------------------------------

⏱️ Time Complexity:
O(m * n)

Each cell visited once.

--------------------------------

🧠 Space Complexity:
O(m * n) worst-case recursion stack

--------------------------------

🧩 Pattern:
Matrix DFS + Connected Components

--------------------------------

🎯 Category:
Graph → Grid DFS/BFS

--------------------------------

🧠 Interview One-Liner:

Run DFS on each group of 1's and
keep the largest component size.

*/

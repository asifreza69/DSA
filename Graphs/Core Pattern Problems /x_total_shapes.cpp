class Solution {
public:

    int m, n;

    vector<vector<int>> dir = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}
    };

    void dfs(int i,
             int j,
             vector<vector<char>>& grid,
             vector<vector<int>>& visited) {

        visited[i][j] = 1;

        for(auto &it : dir) {

            int x = i + it[0];
            int y = j + it[1];

            if(x >= 0 && x < m &&
               y >= 0 && y < n &&
               !visited[x][y] &&
               grid[x][y] == 'X') {

                dfs(x, y, grid, visited);
            }
        }
    }

    int xShape(vector<vector<char>> &grid) {

        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> visited(
            m, vector<int>(n, 0)
        );

        int count = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 'X' &&
                   !visited[i][j]) {

                    dfs(i, j, grid, visited);

                    count++;
                }
            }
        }

        return count;
    }
};

/*
==========================
🔥 X TOTAL SHAPES
==========================

Goal:
Count number of connected groups
of 'X' in the grid.

--------------------------------

🧠 Core Idea:

Every unvisited 'X' cell starts
a new connected component.

Run DFS to mark all cells
belonging to that component.

--------------------------------

Movement:
4 directions only
(up, down, left, right)

--------------------------------

Algorithm:

1. Traverse all cells.
2. If cell = 'X' and unvisited:
      - DFS from it
      - count++
3. Return count.

--------------------------------

Example:

X O O X
X X O X
O O O O
X X X O

Shapes:
1) Top-left cluster
2) Top-right cluster
3) Bottom cluster

Answer = 3

--------------------------------

⏱️ Time Complexity:
O(m * n)

Each cell visited once.

--------------------------------

🧠 Space Complexity:
O(m * n) for visited
+ O(m * n) recursion stack
in worst case.

--------------------------------

🧩 Pattern:
Matrix DFS / Connected Components

--------------------------------

🎯 Category:
Graph → Grid DFS/BFS

--------------------------------

🧠 Interview One-Liner:

Count connected components of 'X'
using DFS in 4 directions.

*/

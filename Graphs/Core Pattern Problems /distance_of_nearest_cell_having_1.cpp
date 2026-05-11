class Solution {
public:

    int m, n;

    vector<vector<int>> nearest(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> dir = {
            {1, 0},
            {0, 1},
            {-1, 0},
            {0, -1}
        };

        queue<pair<int,int>> q;

        // Stores shortest distance to nearest 1
        vector<vector<int>> visited(
            m, vector<int>(n, -1)
        );

        // Push all 1's into queue
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    visited[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Multi-source BFS
        while(!q.empty()) {

            auto [i, j] = q.front();
            q.pop();

            for(auto &it : dir) {

                int x = i + it[0];
                int y = j + it[1];

                if(x >= 0 && x < m &&
                   y >= 0 && y < n &&
                   visited[x][y] == -1) {

                    visited[x][y] =
                        visited[i][j] + 1;

                    q.push({x, y});
                }
            }
        }

        return visited;
    }
};

/*
==========================
🔥 DISTANCE OF NEAREST 1
==========================

Goal:
For every cell, find shortest
distance to any cell containing 1.

--------------------------------

🧠 Core Idea:

Start BFS from all cells
containing 1 simultaneously.

This is called Multi-Source BFS.

--------------------------------

Why Multi-Source BFS?

All 1's are distance 0.
The first time a 0 cell is reached,
that distance is guaranteed minimum.

--------------------------------

Algorithm:

1. Push all cells with value 1.
2. Set their distance = 0.
3. BFS in 4 directions.
4. Unvisited neighbours get:
      dist = current + 1.

--------------------------------

Example:

0 0 0
0 1 0
1 0 0

Output:
1 1 2
1 0 1
0 1 2

--------------------------------

⏱️ Time Complexity:
O(m * n)

Each cell is processed once.

--------------------------------

🧠 Space Complexity:
O(m * n)

Queue + distance matrix.

--------------------------------

🧩 Pattern:
Multi-Source BFS

--------------------------------

🎯 Category:
Graph → Grid BFS

--------------------------------

🧠 Interview One-Liner:

Push all 1's into the queue and
run BFS to compute minimum
distance for every cell.

*/

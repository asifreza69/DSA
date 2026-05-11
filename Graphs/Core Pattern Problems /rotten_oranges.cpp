class Solution {
public:

    int orangesRot(vector<vector<int>>& mat) {

        queue<pair<int,int>> q;

        int m = mat.size();
        int n = mat[0].size();

        int fresh = 0;

        // 4 directions
        vector<vector<int>> dir = {
            {1, 0},
            {0, 1},
            {-1, 0},
            {0, -1}
        };

        // Push all rotten oranges
        // Count fresh oranges
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(mat[i][j] == 2) {
                    q.push({i, j});
                }
                else if(mat[i][j] == 1) {
                    fresh++;
                }
            }
        }

        // No fresh orange exists
        if(fresh == 0) return 0;

        int minutes = 0;

        // Multi-source BFS
        while(!q.empty()) {

            int sz = q.size();

            while(sz--) {

                auto [i, j] = q.front();
                q.pop();

                for(auto &it : dir) {

                    int x = i + it[0];
                    int y = j + it[1];

                    if(x >= 0 && x < m &&
                       y >= 0 && y < n &&
                       mat[x][y] == 1) {

                        // Rot fresh orange
                        mat[x][y] = 2;

                        fresh--;

                        q.push({x, y});
                    }
                }
            }

            minutes++;
        }

        // Some fresh oranges are unreachable
        if(fresh > 0) return -1;

        return minutes - 1;
    }
};

/*
==========================
🔥 ROTTEN ORANGES
==========================

Goal:
Find minimum minutes required
to rot all fresh oranges.

--------------------------------

🧠 Core Idea:

All rotten oranges start spreading
simultaneously.

This is a Multi-Source BFS problem.

--------------------------------

Rules:
- Rotten orange (2) infects
  adjacent fresh orange (1)
- Infection spreads in 4 directions
- Each BFS level = 1 minute

--------------------------------

Algorithm:

1. Push all rotten oranges.
2. Count fresh oranges.
3. Perform BFS level by level.
4. Rot adjacent fresh oranges.
5. If fresh > 0 → return -1.
6. Else return minutes.

--------------------------------

Why return minutes - 1?

The last BFS iteration increments
minutes after processing the final
level, so subtract 1.

--------------------------------

Example:

2 1 1
1 1 0
0 1 1

Answer = 4 minutes

--------------------------------

⏱️ Time Complexity:
O(m * n)

Each cell processed once.

--------------------------------

🧠 Space Complexity:
O(m * n)

Queue in worst case.

--------------------------------

🧩 Pattern:
Multi-Source BFS

--------------------------------

🎯 Category:
Graph → Grid BFS

--------------------------------

🧠 Interview One-Liner:

Push all rotten oranges into queue
and run BFS where each level
represents one minute.

*/

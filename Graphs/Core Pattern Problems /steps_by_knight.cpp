class Solution {
public:
    int minStepToReachTarget(vector<int>& kp,
                             vector<int>& tp,
                             int n) {

        // All 8 knight moves
        vector<vector<int>> dir = {
            {-2, -1}, {-2, 1},
            {-1, -2}, {1, -2},
            {-1, 2},  {1, 2},
            {2, -1},  {2, 1}
        };

        // Already at target
        if(kp == tp) return 0;

        queue<pair<int,int>> q;

        int targetX = tp[0];
        int targetY = tp[1];

        // 1-based indexing
        vector<vector<int>> vis(
            n + 1,
            vector<int>(n + 1, 0)
        );

        q.push({kp[0], kp[1]});
        vis[kp[0]][kp[1]] = 1;

        int steps = 0;

        // BFS
        while(!q.empty()) {

            int sz = q.size();
            steps++;

            while(sz--) {

                auto [i, j] = q.front();
                q.pop();

                for(auto &it : dir) {

                    int x = i + it[0];
                    int y = j + it[1];

                    if(x >= 1 && x <= n &&
                       y >= 1 && y <= n &&
                       vis[x][y] == 0) {

                        // Target reached
                        if(x == targetX &&
                           y == targetY) {
                            return steps;
                        }

                        vis[x][y] = 1;
                        q.push({x, y});
                    }
                }
            }
        }

        return 0;
    }
};

/*
==========================
🔥 STEPS BY KNIGHT
==========================

Goal:
Find minimum number of moves
required for a knight to reach
the target cell.

--------------------------------

🧠 Core Idea:

Each board cell is a graph node.
Knight moves form edges.

We need shortest path in an
unweighted graph → BFS.

--------------------------------

Knight Moves:
8 possible positions.

--------------------------------

Algorithm:

1. Push starting cell.
2. Mark visited.
3. BFS level by level.
4. Each level = one move.
5. First time target is reached,
   return current steps.

--------------------------------

Why BFS?

BFS always finds shortest path
in an unweighted graph.

--------------------------------

⏱️ Time Complexity:
O(n²)

Each cell visited at most once.

--------------------------------

🧠 Space Complexity:
O(n²)

Visited matrix + queue.

--------------------------------

🧩 Pattern:
Shortest Path in Unweighted Graph

--------------------------------

🎯 Category:
Graph → BFS

--------------------------------

🧠 Interview One-Liner:

Treat each cell as a node and use
BFS since every knight move has
equal cost.

*/

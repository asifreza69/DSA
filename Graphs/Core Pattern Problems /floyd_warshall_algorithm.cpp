class Solution {
public:
    void floydWarshall(vector<vector<int>> &dist) {

        int n = dist.size();

        // via = intermediate node
        for(int via = 0; via < n; via++) {

            // source node
            for(int i = 0; i < n; i++) {

                // destination node
                for(int j = 0; j < n; j++) {

                    // avoid overflow for unreachable nodes
                    if(dist[i][via] != 1e8 &&
                       dist[via][j] != 1e8) {

                        dist[i][j] = min(
                            dist[i][j],
                            dist[i][via] + dist[via][j]
                        );
                    }
                }
            }
        }
    }
};

/*
==========================
🔥 FLOYD-WARSHALL
==========================

Goal:
Find shortest distances between
every pair of vertices

--------------------------------

🧠 Core Idea:

Try every node as an intermediate
(via) node

--------------------------------

Transition:

dist[i][j] =
min(dist[i][j],
    dist[i][via] + dist[via][j])

--------------------------------

⏱️ Time Complexity:
O(V^3)

--------------------------------

🧠 Space Complexity:
O(1) extra
(in-place update)

--------------------------------

🧩 Pattern:
Dynamic Programming + All Pairs Shortest Path

--------------------------------

🎯 Category:
Graph → Shortest Path → Floyd-Warshall

--------------------------------

✅ Works With:
- Negative edge weights

❌ Not Valid If:
- Negative cycle exists

--------------------------------

🧠 Interview One-Liner:

Use each vertex as an intermediate
node to improve all pair distances.

*/

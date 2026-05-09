class Solution {
public:

    vector<int> bellmanFord(int V,
                            vector<vector<int>> &edges,
                            int src) {

        // distance array
        vector<int> dist(V, 1e8);

        dist[src] = 0;

        // Relax all edges V-1 times
        for(int count = 1; count <= V - 1; count++) {

            for(auto &it : edges) {

                int u  = it[0];
                int v  = it[1];
                int wt = it[2];

                if(dist[u] != 1e8 &&
                   dist[u] + wt < dist[v]) {

                    dist[v] = dist[u] + wt;
                }
            }
        }

        // Check for negative cycle
        for(auto &it : edges) {

            int u  = it[0];
            int v  = it[1];
            int wt = it[2];

            if(dist[u] != 1e8 &&
               dist[u] + wt < dist[v]) {

                return {-1};
            }
        }

        return dist;
    }
};

/*
==========================
🔥 BELLMAN-FORD ALGORITHM
==========================

Goal:
Find shortest distance from source
to all vertices

--------------------------------

🧠 Core Idea:

Relax every edge exactly V-1 times

Why V-1?
Shortest path can contain
at most V-1 edges

--------------------------------

Relaxation:

if(dist[u] + wt < dist[v])
    dist[v] = dist[u] + wt

--------------------------------

Negative Cycle Detection:

After V-1 relaxations,
if any edge can still relax,
negative cycle exists

--------------------------------

⏱️ Time Complexity:
O(V * E)

--------------------------------

🧠 Space Complexity:
O(V)

--------------------------------

🧩 Pattern:
Shortest Path + Edge Relaxation

--------------------------------

🎯 Category:
Graph → Shortest Path → Bellman-Ford

--------------------------------

✅ Works With:
- Negative weights
- Directed graphs

❌ Detects:
- Negative weight cycles

--------------------------------

🧠 Interview One-Liner:

Relax all edges V-1 times and
check once more for negative cycles.

*/

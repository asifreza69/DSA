class Solution {
public:

    void dfs(int node,
             unordered_map<int, vector<int>>& mp,
             vector<bool>& vis) {

        vis[node] = true;

        for(auto nei : mp[node]) {
            if(!vis[nei]) {
                dfs(nei, mp, vis);
            }
        }
    }

    bool isBridge(int V,
                  vector<vector<int>>& edges,
                  int c,
                  int d) {

        unordered_map<int, vector<int>> mp;

        // Build graph excluding edge (c, d)
        for(auto &it : edges) {

            int u = it[0];
            int v = it[1];

            if((u == c && v == d) ||
               (u == d && v == c)) {
                continue;
            }

            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        vector<bool> vis(V, false);

        // Start DFS from c
        dfs(c, mp, vis);

        // If d is unreachable,
        // removed edge was a bridge
        return !vis[d];
    }
};

/*
==========================
🔥 BRIDGE EDGE IN GRAPH
==========================

Goal:
Check whether edge (c, d) is a bridge.

Bridge:
An edge whose removal increases
the number of connected components.

--------------------------------

🧠 Core Idea (Brute Force):

1. Remove edge (c, d).
2. Run DFS from c.
3. If d becomes unreachable,
   the edge is a bridge.

--------------------------------

Why It Works?

If c and d are still connected,
another path exists.

If disconnected,
this edge was the only connection.

--------------------------------

Example:

0 --- 1 --- 2

Edge (1,2) is a bridge because
removing it disconnects node 2.

--------------------------------

⏱️ Time Complexity:
O(V + E)

Building graph + one DFS.

--------------------------------

🧠 Space Complexity:
O(V + E)

Adjacency list + visited array.

--------------------------------

🧩 Pattern:
Connectivity Check After Edge Removal

--------------------------------

🎯 Category:
Graph → Bridges

--------------------------------

🧠 Optimal Approach:

Tarjan's Algorithm
(using discovery time and low-link)

Time Complexity: O(V + E)

--------------------------------

🧠 Interview One-Liner:

Temporarily remove the edge and
check whether its endpoints are
still connected.

*/

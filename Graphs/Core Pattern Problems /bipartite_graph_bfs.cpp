class Solution {
public:

    bool check(int start,
               int curcolor,
               unordered_map<int, vector<int>>& mp,
               vector<int>& vis) {

        queue<int> q;

        // Assign starting color
        vis[start] = curcolor;
        q.push(start);

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            for(auto nei : mp[node]) {

                // Same color on both ends
                if(vis[nei] == vis[node]) {
                    return false;
                }

                // Not colored yet
                if(vis[nei] == -1) {
                    vis[nei] = 1 - vis[node];
                    q.push(nei);
                }
            }
        }

        return true;
    }

    bool isBipartite(int V, vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> mp;

        // Build undirected graph
        for(auto &it : edges) {
            int u = it[0];
            int v = it[1];

            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        // -1 = uncolored
        //  0 = color A
        //  1 = color B
        vector<int> vis(V, -1);

        // Handle disconnected graph
        for(int i = 0; i < V; i++) {
            if(vis[i] == -1) {
                if(!check(i, 0, mp, vis)) {
                    return false;
                }
            }
        }

        return true;
    }
};

/*
==========================
🔥 BIPARTITE GRAPH
==========================

Goal:
Check whether graph can be colored
using 2 colors such that no two
adjacent nodes have same color.

--------------------------------

🧠 Core Idea:

Use BFS to assign alternate colors.

If two connected nodes get the
same color, graph is not bipartite.

--------------------------------

Color Representation:

-1 → unvisited
 0 → first color
 1 → second color

Neighbour color:
1 - currentColor

--------------------------------

Important Fact:

A graph is bipartite
iff it contains no odd cycle.

--------------------------------

Algorithm:

1. Start BFS from every
   unvisited node.
2. Color start node 0.
3. Color neighbours opposite.
4. If conflict occurs,
   return false.

--------------------------------

Example:

0 — 1
|   |
3 — 2

Bipartite = true

--------------------------------

⏱️ Time Complexity:
O(V + E)

--------------------------------

🧠 Space Complexity:
O(V + E)

--------------------------------

🧩 Pattern:
Graph Coloring + BFS

--------------------------------

🎯 Category:
Graph → Bipartite Checking

--------------------------------

🧠 Interview One-Liner:

Try 2-coloring the graph using BFS.
If any adjacent nodes get same
color, graph is not bipartite.

*/

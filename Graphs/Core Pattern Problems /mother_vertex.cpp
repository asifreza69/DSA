class Solution {
public:

    void bfs(int start,
             unordered_map<int, vector<int>>& mp,
             int V,
             vector<bool>& visited) {

        queue<int> q;
        q.push(start);
        visited[start] = true;

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            for(auto nei : mp[node]) {
                if(!visited[nei]) {
                    visited[nei] = true;
                    q.push(nei);
                }
            }
        }
    }

    int findMotherVertex(int V, vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> mp;

        // Build adjacency list
        for(auto &it : edges) {
            mp[it[0]].push_back(it[1]);
        }

        vector<bool> visited(V, false);

        int maybe = -1;

        // Last BFS start node becomes candidate
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                bfs(i, mp, V, visited);
                maybe = i;
            }
        }

        // Verify candidate
        fill(visited.begin(), visited.end(), false);

        bfs(maybe, mp, V, visited);

        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                return -1;
            }
        }

        return maybe;
    }
};

/*
==========================
🔥 MOTHER VERTEX
==========================

Goal:
Find a vertex from which all
other vertices are reachable.

--------------------------------

🧠 Core Idea:

The last vertex from which a DFS/BFS
is started while traversing all
components is the only possible
mother vertex candidate.

--------------------------------

Algorithm:

1. Traverse all nodes.
2. Whenever an unvisited node is found:
      run BFS/DFS.
      candidate = current node.
3. Reset visited.
4. Run BFS/DFS from candidate.
5. If all nodes visited:
      candidate is mother vertex.
   Else:
      no mother vertex.

--------------------------------

Why It Works?

The last finished source lies in
the source strongly connected
component of the graph.

--------------------------------

⏱️ Time Complexity:
O(V + E)

Two graph traversals.

--------------------------------

🧠 Space Complexity:
O(V + E)

--------------------------------

🧩 Pattern:
DFS/BFS Reachability

--------------------------------

🎯 Category:
Graph → Reachability

--------------------------------

🧠 Interview One-Liner:

The last node that starts a graph
traversal is the only possible
mother vertex candidate.

*/

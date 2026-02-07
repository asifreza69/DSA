// LeetCode 3243: Shortest Distance After Road Addition Queries I
// Approach:
// Initially, the graph is a linear chain from 0 -> 1 -> 2 -> ... -> n-1.
// For each query, add a directed edge (u -> v).
// After each edge addition, run BFS from node 0 to find the
// shortest distance to node n-1.
//
// BFS is used because the graph is unweighted and we need
// the minimum number of edges.
//
// Time Complexity:
// O(Q * (N + E)) — BFS for each query.
//
// Space Complexity:
// O(N + E) — adjacency list, queue, and visited array.

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(
        int n,
        vector<vector<int>>& queries) {

        unordered_map<int, vector<int>> mp;
        vector<int> ans;

        // Initial linear graph: i -> i+1
        for (int i = 0; i < n - 1; i++) {
            mp[i].push_back(i + 1);
        }

        // Process each query
        for (auto& it : queries) {

            // Add new directed edge
            mp[it[0]].push_back(it[1]);

            queue<int> q;
            vector<bool> visited(n, false);

            q.push(0);
            visited[0] = true;

            int level = 0;
            bool found = false;

            // BFS to find shortest path from 0 to n-1
            while (!q.empty() && !found) {

                int sz = q.size();

                while (sz--) {
                    int node = q.front();
                    q.pop();

                    // Destination reached
                    if (node == n - 1) {
                        found = true;
                        break;
                    }

                    // Visit neighbors
                    for (auto& nxt : mp[node]) {
                        if (!visited[nxt]) {
                            visited[nxt] = true;
                            q.push(nxt);
                        }
                    }
                }

                // Increase distance after each BFS layer
                if (!found) {
                    level++;
                }
            }

            // Store result for current query
            ans.push_back(found ? level : -1);
        }

        return ans;
    }
};

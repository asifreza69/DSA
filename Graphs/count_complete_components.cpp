// LeetCode 2685: Count the Number of Complete Components
// Approach:
// Treat the graph as an undirected graph.
// Use DFS to explore each connected component.
// For every component, count:
// 1) Number of nodes
// 2) Number of edges
//
// A component is complete if:
// edges == nodes * (nodes - 1) / 2
//
// Since each edge is counted twice in adjacency list,
// divide edge count by 2 before comparison.
//
// Time Complexity:
// O(n + e) — DFS traversal over all nodes and edges.
//
// Space Complexity:
// O(n + e) — adjacency list + visited array.

class Solution {
public:
    int edgesCount = 0;
    int nodesCount = 0;

    // DFS to count nodes and edges in a component
    void dfs(int i,
             int& edgesCount,
             int& nodesCount,
             vector<bool>& visited,
             unordered_map<int, vector<int>>& mp) {

        visited[i] = true;
        nodesCount++;
        edgesCount += mp[i].size();

        for (auto& it : mp[i]) {
            if (!visited[it]) {
                dfs(it, edgesCount, nodesCount, visited, mp);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> mp;

        // Build adjacency list
        for (auto& e : edges) {
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        int ans = 0;

        // Traverse each connected component
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {

                edgesCount = 0;
                nodesCount = 0;

                dfs(i, edgesCount, nodesCount, visited, mp);

                // Each edge is counted twice
                edgesCount /= 2;

                // Check if component is complete
                if (edgesCount == nodesCount * (nodesCount - 1) / 2) {
                    ans++;
                }
            }
        }

        return ans;
    }
};

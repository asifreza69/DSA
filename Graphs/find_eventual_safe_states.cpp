// LeetCode 802: Find Eventual Safe States
// Approach: Reverse the graph and apply Kahn’s Algorithm (Topological Sort).
//           Nodes with indegree 0 are terminal and considered safe.
//           Gradually mark all nodes that eventually lead to terminal nodes as safe.
// Time Complexity: O(V + E)
// Space Complexity: O(V + E)

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();

        vector<vector<int>> adj(V);
        queue<int> que;
        vector<int> indegree(V, 0);

        // Reverse the graph and compute indegree
        for(int u = 0; u < V; u++) {
            for(int &v : graph[u]) {
                adj[v].push_back(u);
                indegree[u]++;
            }
        }

        // Push all nodes with indegree 0
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) {
                que.push(i);
            }
        }

        vector<bool> safe(V, false);

        // BFS using Kahn's Algorithm
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            safe[u] = true;

            for(int &v : adj[u]) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    que.push(v);
                }
            }
        }

        // Collect all safe nodes
        vector<int> safeNodes;
        for(int i = 0; i < V; i++) {
            if(safe[i]) {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
};

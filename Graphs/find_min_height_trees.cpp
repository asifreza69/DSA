// LeetCode 310: Minimum Height Trees
// Approach:
// A tree's Minimum Height Trees (MHTs) are always the center(s) of the tree.
// We use a BFS-based "leaf trimming" approach:
//
// 1. Build the graph using an adjacency list.
// 2. Store the degree (indegree) of each node.
// 3. Push all leaf nodes (degree == 1) into a queue.
// 4. Repeatedly remove leaves layer by layer.
// 5. The last remaining 1 or 2 nodes are the roots of MHTs.
//
// This is similar to topological sorting on an undirected graph.
//
// Time Complexity:
// O(N) — each node and edge is processed once.
//
// Space Complexity:
// O(N) — adjacency list, degree array, and queue.

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        // Edge case: only one node
        if (n == 1) {
            return {0};
        }

        unordered_map<int, vector<int>> mp;
        vector<int> indegree(n, 0);
        queue<int> q;

        // Build graph and degree count
        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }

        // Push all leaf nodes into queue
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 1) {
                q.push(i);
            }
        }

        // Remove leaves until <= 2 nodes remain
        while (n > 2) {

            int sz = q.size();
            n -= sz;

            while (sz--) {
                int node = q.front();
                q.pop();

                for (auto& nei : mp[node]) {
                    indegree[nei]--;
                    if (indegree[nei] == 1) {
                        q.push(nei);
                    }
                }
            }
        }

        // Remaining nodes are MHT roots
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};

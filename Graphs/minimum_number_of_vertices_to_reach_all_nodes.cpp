// LeetCode 1557: Minimum Number of Vertices to Reach All Nodes
// Approach:
// In a directed graph, any node with an incoming edge
// can be reached from some other node.
// Therefore, nodes with indegree = 0 must be included
// in the answer set.
//
// Traverse all edges and mark destination nodes.
// Finally, collect all nodes that were never marked.
//
// Time Complexity:
// O(n + e) — where e is the number of edges.
//
// Space Complexity:
// O(n) — for indegree tracking.

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n,
                                          vector<vector<int>>& edges) {

        vector<bool> hasIncoming(n, false);

        // Mark nodes having incoming edges
        for (auto& e : edges) {
            hasIncoming[e[1]] = true;
        }

        vector<int> ans;

        // Nodes without incoming edges are required
        for (int i = 0; i < n; i++) {
            if (!hasIncoming[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

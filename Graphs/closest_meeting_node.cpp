class Solution {
public:

    // DFS to calculate distance from a given start node
    // edges -> directed graph representation
    // node  -> current node
    // d     -> distance array
    // v     -> visited array
    void dfs(vector<int>& edges, int node, vector<int>& d, vector<bool>& v) {
        v[node] = true;

        int next = edges[node];
        // Move to next node if it exists and is not visited
        if (next != -1 && !v[next]) {
            d[next] = d[node] + 1;
            dfs(edges, next, d, v);
        }
    }

    // Finds the node reachable from both node1 and node2
    // such that the maximum distance from both is minimized
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();

        // Distance arrays for both nodes
        vector<int> d1(n, INT_MAX);
        vector<int> d2(n, INT_MAX);

        // Visited arrays for DFS
        vector<bool> v1(n, false);
        vector<bool> v2(n, false);

        // Starting points
        d1[node1] = 0;
        d2[node2] = 0;

        // DFS traversal from both nodes
        dfs(edges, node1, d1, v1);
        dfs(edges, node2, d2, v2);

        int minDist = INT_MAX;
        int result = -1;

        // Find the node minimizing the maximum distance
        for (int i = 0; i < n; i++) {
            if (d1[i] != INT_MAX && d2[i] != INT_MAX) {
                int maxDist = max(d1[i], d2[i]);
                if (maxDist < minDist) {
                    minDist = maxDist;
                    result = i;
                }
            }
        }

        return result;
    }
};

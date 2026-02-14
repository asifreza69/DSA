// LeetCode 3108: Minimum Cost Walk in Weighted Graph
//
// Approach: Disjoint Set Union (Union-Find)
//
// Idea:
// - We group nodes into connected components using DSU.
// - For each component, maintain the bitwise AND of all edge weights
//   inside that component.
// - If two nodes belong to different components → answer = -1.
// - If they belong to same component → answer = AND value of that component.
//
// Important:
// - Initial cost is -1 (all bits set).
// - Every edge weight is ANDed into its component's cost.
//
// Time Complexity:
// - O(E * α(N) + Q * α(N))
//
// Space Complexity:
// - O(N)

class Solution {
public:
    
    vector<int> parent;
    
    // Find with path compression
    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    
    // Union operation
    void Union(int x, int y) {
        parent[y] = x;
    }
    
    vector<int> minimumCost(int n,
                            vector<vector<int>>& edges,
                            vector<vector<int>>& query) {
        
        parent.resize(n);
        vector<int> cost(n, -1);  // AND cost per component
        
        // Initialize DSU
        for (int i = 0; i < n; i++)
            parent[i] = i;
        
        // Process edges
        for (auto &edge : edges) {
            
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            int pu = find(u);
            int pv = find(v);
            
            if (pu != pv) {
                Union(pu, pv);
                cost[pu] &= cost[pv];
            }
            
            cost[find(u)] &= wt;
        }
        
        vector<int> ans;
        
        // Process queries
        for (auto &q : query) {
            
            int u = q[0];
            int v = q[1];
            
            if (find(u) != find(v)) {
                ans.push_back(-1);
            } else {
                ans.push_back(cost[find(u)]);
            }
        }
        
        return ans;
    }
};

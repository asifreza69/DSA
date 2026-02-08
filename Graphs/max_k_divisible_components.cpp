// LeetCode 2872: Maximum Number of K-Divisible Components
//
// Approach: DFS on Tree
//
// Idea:
// - Tree diya hua hai (n nodes, n-1 edges)
// - DFS root (0) se start karte hain
// - Har node ke subtree ka sum calculate karte hain
// - Agar subtree sum % k == 0:
//     -> Ye ek valid component ban sakta hai
//     -> Count increase karo
//     -> Parent ko 0 return karo (edge cut ho gaya)
//
// Why return 0?
// - Taaki upar wale subtree me iska sum include na ho
// - Isse maximum components milte hain
//
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int count;

    int dfs(int curr, int parent,
            unordered_map<int, vector<int>>& adj,
            vector<int>& values, int k) {

        int sum = values[curr];

        for (int ngbr : adj[curr]) {
            if (ngbr != parent) {
                sum += dfs(ngbr, curr, adj, values, k);
                sum %= k;
            }
        }

        // Agar current subtree ka sum k se divisible hai
        if (sum % k == 0) {
            count++;      // ek component mil gaya
            return 0;     // edge cut
        }

        return sum;
    }

    int maxKDivisibleComponents(int n,
                                vector<vector<int>>& edges,
                                vector<int>& values,
                                int k) {

        unordered_map<int, vector<int>> adj;

        // Graph construction
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        count = 0;
        dfs(0, -1, adj, values, k);

        return count;
    }
};

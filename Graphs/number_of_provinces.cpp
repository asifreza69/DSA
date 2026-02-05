// LeetCode 547: Number of Provinces
// Approach:
// Treat the cities as nodes of a graph.
// If isConnected[i][j] == 1, there is an edge between city i and city j.
// Use DFS to find connected components in the graph.
// Each connected component represents one province.
//
// Time Complexity:
// O(n * n) — due to adjacency matrix traversal.
//
// Space Complexity:
// O(n) — visited array + recursion stack.

class Solution {
public:
    // DFS to visit all cities in the same province
    void dfs(int i,
             unordered_map<int, vector<int>>& mp,
             vector<bool>& visited) {

        visited[i] = true;

        // Visit all directly connected cities
        for (auto& it : mp[i]) {
            if (!visited[it]) {
                dfs(it, mp, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        unordered_map<int, vector<int>> mp;
        int n = isConnected.size();

        // Build adjacency list from adjacency matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    mp[i].push_back(j);
                }
            }
        }

        vector<bool> visited(n, false);
        int count = 0;

        // Count connected components using DFS
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, mp, visited);
                count++;
            }
        }

        return count;
    }
};

class Solution {
public:
    // DFS traversal to explore all reachable cities
    // and keep updating the minimum edge weight
    void dfs(int i,
             unordered_map<int, vector<pair<int,int>>>& mp,
             vector<bool>& visited,
             int& ans) {

        visited[i] = true;

        // Traverse all connected roads
        for (auto& it : mp[i]) {
            // Update the minimum score encountered so far
            ans = min(ans, it.second);

            // Visit unvisited neighboring city
            if (!visited[it.first]) {
                dfs(it.first, mp, visited, ans);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {

        // Adjacency list: city -> {neighbor, distance}
        unordered_map<int, vector<pair<int,int>>> mp;

        // Build the graph
        for (auto& r : roads) {
            mp[r[0]].push_back({r[1], r[2]});
            mp[r[1]].push_back({r[0], r[2]});
        }

        vector<bool> visited(n + 1, false);
        int ans = INT_MAX;

        // Start DFS from city 1
        dfs(1, mp, visited, ans);

        // Minimum score of any path reachable from city 1
        return ans;
    }
};

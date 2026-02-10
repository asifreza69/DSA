// LeetCode 787: Cheapest Flights Within K Stops
//
// Approach: BFS with Cost Relaxation (Level-wise Traversal)
//
// Idea:
// - Each BFS level represents one stop
// - Use BFS up to k stops
// - Track minimum cost to reach each city
// - Relax edges only if we find a cheaper cost
//
// Why BFS instead of Dijkstra?
// - Constraint is on number of stops, not minimum distance
// - BFS naturally handles level (stop) limitation
//
// Time Complexity:
// - O(k * E)
//
// Space Complexity:
// - O(V + E)

class Solution {
public:
    int findCheapestPrice(int n,
                          vector<vector<int>>& flights,
                          int src,
                          int dst,
                          int k) {

        // Adjacency list: u -> {v, cost}
        unordered_map<int, vector<pair<int, int>>> mp;
        for (auto& f : flights) {
            mp[f[0]].push_back({f[1], f[2]});
        }

        // ans[i] = minimum cost to reach city i
        vector<int> ans(n, INT_MAX);
        ans[src] = 0;

        // {current city, total cost so far}
        queue<pair<int, int>> q;
        q.push({src, 0});

        int steps = 0;

        // BFS level by level (each level = one stop)
        while (!q.empty() && steps <= k) {
            int size = q.size();

            while (size--) {
                auto [u, cost] = q.front();
                q.pop();

                for (auto& it : mp[u]) {
                    int v = it.first;
                    int price = it.second;

                    // Relax edge if cheaper cost found
                    if (cost + price < ans[v]) {
                        ans[v] = cost + price;
                        q.push({v, ans[v]});
                    }
                }
            }

            steps++;
        }

        return ans[dst] == INT_MAX ? -1 : ans[dst];
    }
};

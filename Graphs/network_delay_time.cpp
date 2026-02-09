// LeetCode 743: Network Delay Time
//
// Approach: Dijkstra's Algorithm (Single Source Shortest Path)
//
// Explanation:
// - Each node represents a network node
// - times[i] = {u, v, w} means signal takes w time to go from u to v
// - We want the minimum time for the signal to reach all nodes starting from k
//
// Key Idea:
// - Use Dijkstra to find shortest distance from source k to every node
// - The answer is the maximum distance among all reachable nodes
// - If any node is unreachable, return -1
//
// Time Complexity:
// - O(E log V), where E = number of edges, V = number of nodes
//
// Space Complexity:
// - O(V + E)

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // Adjacency list: node -> {neighbor, weight}
        unordered_map<int, vector<pair<int, int>>> mp;

        // Min-heap: {distance, node}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        // res[i] stores shortest distance from k to node i
        vector<int> res(n + 1, INT_MAX);

        // Build graph
        for (auto &t : times) {
            int u = t[0];
            int v = t[1];
            int w = t[2];
            mp[u].push_back({v, w});
        }

        // Start from source node k
        pq.push({0, k});
        res[k] = 0;

        // Dijkstra's algorithm
        while (!pq.empty()) {
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Relax edges
            for (auto &it : mp[node]) {
                int nextNode = it.first;
                int edgeWeight = it.second;

                if (distance + edgeWeight < res[nextNode]) {
                    res[nextNode] = distance + edgeWeight;
                    pq.push({res[nextNode], nextNode});
                }
            }
        }

        // Find maximum distance
        int ans = INT_MIN;
        for (int i = 1; i <= n; i++) {
            // If any node is unreachable
            if (res[i] == INT_MAX)
                return -1;

            ans = max(ans, res[i]);
        }

        return ans;
    }
};

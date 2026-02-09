// LeetCode 1584: Min Cost to Connect All Points
//
// Approach: Prim's Algorithm (Minimum Spanning Tree)
//
// Explanation:
// - Each point is treated as a node in a graph
// - Edge weight = Manhattan distance between two points
// - We want to connect all points with minimum total cost
// - This is a classic Minimum Spanning Tree (MST) problem
//
// Steps:
// 1. Build a complete graph using Manhattan distance
// 2. Apply Prim’s algorithm using a min-heap
// 3. Keep adding the smallest edge that connects a new node
//
// Time Complexity:
// - O(N^2 log N) due to complete graph construction
//
// Space Complexity:
// - O(N^2) for adjacency list

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        // Adjacency list: node -> {neighbor, distance}
        vector<vector<pair<int, int>>> adj(n);

        // To mark visited nodes in MST
        vector<bool> visited(n, false);

        // Min-heap: {cost, node}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        int sum = 0;  // Total cost of MST

        // Build complete graph using Manhattan distance
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int distance = abs(points[i][0] - points[j][0]) +
                               abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, distance});
                adj[j].push_back({i, distance});
            }
        }

        // Start MST from node 0
        pq.push({0, 0});

        // Prim's Algorithm
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            int cost = p.first;
            int node = p.second;

            // Skip if already included in MST
            if (visited[node])
                continue;

            visited[node] = true;
            sum += cost;

            // Push all adjacent edges
            for (auto &it : adj[node]) {
                int neigh = it.first;
                int wt = it.second;

                if (!visited[neigh]) {
                    pq.push({wt, neigh});
                }
            }
        }

        return sum;
    }
};

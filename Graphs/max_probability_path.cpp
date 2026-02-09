// LeetCode 1514: Path with Maximum Probability
//
// Approach: Modified Dijkstra’s Algorithm (Max-Heap)
//
// Explanation:
// - Each node represents a vertex in the graph
// - Edge weight represents success probability
// - Instead of minimizing distance, we maximize probability
// - Use a max-heap to always process the path with highest probability first
//
// Steps:
// 1. Build an adjacency list with (neighbor, probability)
// 2. Use a priority queue (max-heap) storing {probability, node}
// 3. Start from 'start' with probability 1.0
// 4. Relax edges if current path gives higher probability
//
// Time Complexity:
// - O(E log V)
//
// Space Complexity:
// - O(V + E)

class Solution {
public:
    double maxProbability(int n,
                          vector<vector<int>>& edges,
                          vector<double>& succProb,
                          int start,
                          int end) {

        // Graph: node -> {neighbor, probability}
        unordered_map<int, vector<pair<int, double>>> adj;

        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        // Max-heap: {probability, node}
        priority_queue<pair<double, int>> pq;

        // Maximum probability to reach each node
        vector<double> prob(n, 0.0);

        pq.push({1.0, start});
        prob[start] = 1.0;

        // Modified Dijkstra
        while (!pq.empty()) {
            double currProb = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // If we already found a better probability, skip
            if (currProb < prob[node])
                continue;

            for (auto &it : adj[node]) {
                int neigh = it.first;
                double edgeProb = it.second;

                double newProb = currProb * edgeProb;

                if (newProb > prob[neigh]) {
                    prob[neigh] = newProb;
                    pq.push({newProb, neigh});
                }
            }
        }

        return prob[end];
    }
};

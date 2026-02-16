// LeetCode 1976: Number of Ways to Arrive at Destination
//
// Approach: Dijkstra + Path Counting
//
// Idea:
// - Use Dijkstra to compute shortest distance from node 0 to all nodes.
// - Maintain an additional array `count[]`:
//      count[i] = number of shortest ways to reach node i.
// - If we find a strictly shorter path → update distance and reset count.
// - If we find an equal shortest path → add to count.
//
// Important:
// - Use long long for distances (can overflow int).
// - Take modulo 1e9+7 for number of ways.
//
// Time Complexity: O(E log V)
// Space Complexity: O(V + E)

class Solution {
public:
    
    typedef pair<long long,int> P;   // {distance, node}
    const int MOD = 1e9 + 7;
    
    int countPaths(int n, vector<vector<int>>& roads) {
        
        // Adjacency list: node -> {neighbor, time}
        unordered_map<int, vector<pair<int,int>>> adj;
        
        for (auto &r : roads) {
            int u = r[0];
            int v = r[1];
            int t = r[2];
            
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }
        
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        
        dist[0] = 0;
        ways[0] = 1;
        
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});
        
        while (!pq.empty()) {
            
            auto [currDist, node] = pq.top();
            pq.pop();
            
            // Skip outdated entries
            if (currDist > dist[node])
                continue;
            
            for (auto &neighbor : adj[node]) {
                
                int nextNode = neighbor.first;
                int weight = neighbor.second;
                
                long long newDist = currDist + weight;
                
                // Found shorter path
                if (newDist < dist[nextNode]) {
                    dist[nextNode] = newDist;
                    ways[nextNode] = ways[node];
                    pq.push({newDist, nextNode});
                }
                // Found another shortest path
                else if (newDist == dist[nextNode]) {
                    ways[nextNode] = (ways[nextNode] + ways[node]) % MOD;
                }
            }
        }
        
        return ways[n - 1];
    }
};

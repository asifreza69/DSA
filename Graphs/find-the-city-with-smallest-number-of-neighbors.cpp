// LeetCode 1334: Find the City With the Smallest Number of Neighbors
//
// Approach: Floyd–Warshall Algorithm (All-Pairs Shortest Path)
//
// Idea:
// - Create an adjacency matrix to store shortest distances.
// - Initialize distance of self to 0 and others to large value (INF).
// - Fill matrix using given edges (undirected graph).
// - Apply Floyd–Warshall to compute shortest path between all pairs.
// - For each city, count how many cities are reachable within distanceThreshold.
// - Return the city with the smallest reachable count.
// - If multiple cities have same count, return the greatest index.
//
// Time Complexity: O(n³)
// Space Complexity: O(n²)

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        const int INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(n, INF));
        
        // Distance to itself is 0
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
        
        // Fill initial edge weights
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            dist[u][v] = wt;
            dist[v][u] = wt;
        }
        
        // Floyd–Warshall Algorithm
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][via] + dist[via][j] < dist[i][j]) {
                        dist[i][j] = dist[i][via] + dist[via][j];
                    }
                }
            }
        }
        
        int minReachable = INT_MAX;
        int resultCity = -1;
        
        // Count reachable cities within threshold
        for (int i = 0; i < n; i++) {
            int count = 0;
            
            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            
            // Choose city with smallest count
            // If tie, choose larger index
            if (count <= minReachable) {
                minReachable = count;
                resultCity = i;
            }
        }
        
        return resultCity;
    }
};

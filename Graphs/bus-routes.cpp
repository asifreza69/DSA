// LeetCode 815: Bus Routes
//
// Approach: BFS on Bus Routes
//
// Idea:
// - Treat each bus route as a node in a graph.
// - Two routes are connected if they share a common bus stop.
// - Start BFS from all routes that contain the source stop.
// - Each BFS level represents taking one additional bus.
// - Stop when we find a route that contains the target stop.
//
// Time Complexity: O(N * M)
//   N = number of routes
//   M = average stops per route
//
// Space Complexity: O(N + total stops)

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        if (source == target)
            return 0;
        
        int n = routes.size();
        
        // Map: bus stop -> list of routes containing that stop
        unordered_map<int, vector<int>> stopToRoutes;
        
        for (int i = 0; i < n; i++) {
            for (int stop : routes[i]) {
                stopToRoutes[stop].push_back(i);
            }
        }
        
        // Track visited routes to avoid cycles
        vector<bool> visited(n, false);
        
        queue<int> q;
        
        // Initialize BFS with all routes containing source
        for (int route : stopToRoutes[source]) {
            q.push(route);
            visited[route] = true;
        }
        
        int buses = 1;
        
        while (!q.empty()) {
            
            int size = q.size();
            
            while (size--) {
                
                int routeIndex = q.front();
                q.pop();
                
                // Check all stops of this route
                for (int stop : routes[routeIndex]) {
                    
                    if (stop == target)
                        return buses;
                    
                    // Explore neighboring routes via this stop
                    for (int nextRoute : stopToRoutes[stop]) {
                        if (!visited[nextRoute]) {
                            visited[nextRoute] = true;
                            q.push(nextRoute);
                        }
                    }
                }
            }
            
            buses++;
        }
        
        return -1;
    }
};

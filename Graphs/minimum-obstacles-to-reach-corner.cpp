// LeetCode 2290: Minimum Obstacle Removal to Reach Corner
//
// Approach: Dijkstra’s Algorithm (Min Heap)
//
// Idea:
// - Each cell represents a node.
// - Moving to a cell with value 1 costs 1 (remove obstacle).
// - Moving to a cell with value 0 costs 0.
// - Use a priority queue (min-heap) to always process the cell
//   with the minimum obstacles removed so far.
// - This is a classic shortest path problem on a grid.
//
// Time Complexity: O(m * n log(m * n))
// Space Complexity: O(m * n)

class Solution {
public:
    #define P pair<int, pair<int,int>>   // {cost, {row, col}}
    
    vector<vector<int>> dir{{1,0},{0,1},{-1,0},{0,-1}};
    
    int minimumObstacles(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        // Distance matrix to store minimum obstacles removed to reach each cell
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        
        // Min-heap based on obstacle count
        priority_queue<P, vector<P>, greater<P>> pq;
        
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        
        while (!pq.empty()) {
            
            auto top = pq.top();
            pq.pop();
            
            int cost = top.first;
            int i = top.second.first;
            int j = top.second.second;
            
            // If we reached destination, return cost
            if (i == m - 1 && j == n - 1)
                return cost;
            
            // Skip if already found a better path
            if (cost > dist[i][j])
                continue;
            
            // Explore all 4 directions
            for (auto& d : dir) {
                
                int x = i + d[0];
                int y = j + d[1];
                
                if (x >= 0 && y >= 0 && x < m && y < n) {
                    
                    int newCost = cost + grid[x][y];
                    
                    if (newCost < dist[x][y]) {
                        dist[x][y] = newCost;
                        pq.push({newCost, {x, y}});
                    }
                }
            }
        }
        
        return dist[m-1][n-1];
    }
};

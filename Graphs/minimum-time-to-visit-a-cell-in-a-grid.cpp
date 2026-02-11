// LeetCode 2577: Minimum Time to Visit a Cell In a Grid
//
// Approach: Dijkstra (Min Heap)
//
// Idea:
// - Each cell has a minimum time constraint grid[i][j].
// - You can move in 4 directions (cost = 1 second per move).
// - If you reach a cell earlier than allowed time,
//   you must wait (adjust time using parity logic).
//
// Important:
// - If both right and down from (0,0) are > 1, it's impossible.
// - Use Dijkstra to always expand minimum time state.
// - If arrival time < grid value, adjust using:
//     If (grid[x][y] - currentTime) % 2 == 0 → wait 1 extra second.
//
// Time Complexity: O(m * n log(m * n))
// Space Complexity: O(m * n)

class Solution {
public:
    
    #define P pair<int, pair<int,int>>   // {time, {row, col}}
    
    int minimumTime(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        // Edge case: cannot move from start
        if (m > 1 && n > 1 && grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }
        
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;
        
        pq.push({0, {0, 0}});
        dist[0][0] = 0;
        
        vector<vector<int>> dir{{1,0},{0,1},{-1,0},{0,-1}};
        
        while (!pq.empty()) {
            
            auto [time, cell] = pq.top();
            pq.pop();
            
            int i = cell.first;
            int j = cell.second;
            
            if (i == m-1 && j == n-1)
                return time;
            
            if (time > dist[i][j])
                continue;
            
            for (auto &d : dir) {
                
                int x = i + d[0];
                int y = j + d[1];
                
                if (x < 0 || y < 0 || x >= m || y >= n)
                    continue;
                
                int newTime = time + 1;
                
                // If we arrive before allowed time, wait
                if (newTime < grid[x][y]) {
                    int diff = grid[x][y] - newTime;
                    
                    if (diff % 2 == 0)
                        newTime = grid[x][y] + 1;
                    else
                        newTime = grid[x][y];
                }
                
                if (newTime < dist[x][y]) {
                    dist[x][y] = newTime;
                    pq.push({newTime, {x, y}});
                }
            }
        }
        
        return -1;
    }
};

// LeetCode 286: Walls and Gates
//
// Approach: Multi-Source BFS
//
// Idea:
// - All gates (cells with value 0) are starting points.
// - Perform BFS from all gates simultaneously.
// - Each BFS level represents distance from nearest gate.
// - Update only empty rooms (value = 2147483647).
//
// Why Multi-Source BFS?
// - Ensures shortest distance to nearest gate.
// - More efficient than running BFS from each empty room.
//
// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

class Solution {
public:
    
    void islandsAndTreasure(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int,int>> q;
        
        // Push all gates into queue (multi-source BFS)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        
        vector<vector<int>> dir{{1,0},{0,1},{-1,0},{0,-1}};
        
        int level = 1;
        
        while (!q.empty()) {
            
            int size = q.size();
            
            while (size--) {
                
                auto [i, j] = q.front();
                q.pop();
                
                for (auto &d : dir) {
                    
                    int x = i + d[0];
                    int y = j + d[1];
                    
                    // Update only empty rooms
                    if (x >= 0 && y >= 0 && x < m && y < n &&
                        grid[x][y] == 2147483647) {
                        
                        grid[x][y] = level;
                        q.push({x, y});
                    }
                }
            }
            
            level++;
        }
    }
};

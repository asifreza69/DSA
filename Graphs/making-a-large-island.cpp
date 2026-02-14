// LeetCode 827: Making A Large Island
//
// Approach: DFS + Component Labeling
//
// Idea:
// 1. Traverse the grid and assign a unique id (starting from 2)
//    to each connected island using DFS.
// 2. Store the size of each island in a map: id -> size.
// 3. For every 0 cell, check its 4 neighbors.
//    Combine sizes of unique neighboring islands.
// 4. Maximum possible size after flipping one 0 is the answer.
//
// Why start id from 2?
// - 0 and 1 are already used in grid.
// - So we label islands as 2, 3, 4, ...
//
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)

class Solution {
public:
    
    int m, n;
    
    vector<vector<int>> dir{{1,0},{0,1},{-1,0},{0,-1}};
    
    // DFS to label island and count its size
    void dfs(int i, int j, int& count,
             vector<vector<int>>& grid,
             vector<vector<bool>>& visited,
             int id) {
        
        for (auto &d : dir) {
            
            int x = i + d[0];
            int y = j + d[1];
            
            if (x >= 0 && y >= 0 && x < m && y < n &&
                !visited[x][y] && grid[x][y] == 1) {
                
                visited[x][y] = true;
                grid[x][y] = id;
                count++;
                
                dfs(x, y, count, grid, visited, id);
            }
        }
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        
        m = grid.size();
        n = grid[0].size();
        
        bool allOne = true;
        
        // Check if grid is already all 1s
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    allOne = false;
                    break;
                }
            }
        }
        
        if (allOne)
            return m * n;
        
        int id = 2;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        unordered_map<int, int> islandSize;
        
        // Label each island and compute its size
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                if (grid[i][j] == 1 && !visited[i][j]) {
                    
                    int count = 1;
                    visited[i][j] = true;
                    grid[i][j] = id;
                    
                    dfs(i, j, count, grid, visited, id);
                    
                    islandSize[id] = count;
                    id++;
                }
            }
        }
        
        int maxIsland = 0;
        
        // Try converting each 0 into 1
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                if (grid[i][j] == 0) {
                    
                    unordered_set<int> uniqueIslands;
                    
                    for (auto &d : dir) {
                        int x = i + d[0];
                        int y = j + d[1];
                        
                        if (x >= 0 && y >= 0 && x < m && y < n &&
                            grid[x][y] > 1) {
                            uniqueIslands.insert(grid[x][y]);
                        }
                    }
                    
                    int newSize = 1;  // flipping this 0
                    
                    for (int islandId : uniqueIslands) {
                        newSize += islandSize[islandId];
                    }
                    
                    maxIsland = max(maxIsland, newSize);
                }
            }
        }
        
        return maxIsland;
    }
};

// LeetCode 1568: Minimum Number of Days to Disconnect Island
// Approach:
// 1. Count number of islands using DFS
// 2. If already disconnected (0 or >1 islands) → return 0
// 3. Try removing each land cell once and check islands → if disconnected → return 1
// 4. Otherwise answer will always be 2
// Time Complexity: O((m*n)^2)
// Space Complexity: O(m*n)

class Solution {
public:
    int m, n;
    vector<vector<int>> dir{{1,0},{0,1},{-1,0},{0,-1}};

    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        visited[i][j] = true;
        
        for(auto& it : dir){
            int x_ = it[0] + i;
            int y_ = it[1] + j;
            if(x_ >= 0 && y_ >= 0 && x_ < m && y_ < n && grid[x_][y_] != 0 && visited[x_][y_] == false){
                dfs(x_, y_, grid, visited);
            }
        }
    }
   
    int findnoisland(vector<vector<int>>& grid){
        int count = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && visited[i][j] == false){
                    count++;
                    dfs(i, j, grid, visited);
                }
            }
        }
        return count;
    }

    int minDays(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int island = findnoisland(grid);

        if(island == 0 || island > 1){
            return 0;
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;

                    int ans = findnoisland(grid);
                    if(ans > 1 || ans == 0){
                        return 1;
                    }

                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};

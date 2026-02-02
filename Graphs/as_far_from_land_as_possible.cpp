class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        // Direction vectors: down, right, up, left
        vector<vector<int>> dir{{1,0},{0,1},{-1,0},{0,-1}};

        // Step 1: Push all land cells into queue (multi-source BFS)
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                }
            }
        }

        // If no land exists OR all cells are land
        if(q.empty() || q.size() == n * m){
            return -1;
        }

        int level = -1;

        // Step 2: BFS expansion layer by layer
        while(!q.empty()){
            int sz = q.size();
            level++;

            while(sz--){
                auto p = q.front();
                q.pop();

                int x = p.first;
                int y = p.second;

                // Explore all 4 directions
                for(auto &d : dir){
                    int x_ = x + d[0];
                    int y_ = y + d[1];

                    // Visit valid water cells
                    if(x_ >= 0 && y_ >= 0 && x_ < n && y_ < m && grid[x_][y_] == 0){
                        grid[x_][y_] = 1;   // mark as visited
                        q.push({x_, y_});
                    }
                }
            }
        }

        // Maximum distance from land
        return level;
    }
};

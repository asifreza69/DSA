// LeetCode 994: Rotting Oranges
// Approach: Use BFS starting from all initially rotten oranges.
//           Each BFS level represents one minute of rotting spread.
// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int fresh = 0;
        int count = 0;

        // Initialize queue with all rotten oranges and count fresh ones
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        if(fresh == 0){
            return 0;
        }

        vector<vector<int>> dir{{0,1}, {1,0}, {-1,0}, {0,-1}};

        // BFS traversal
        while(!q.empty()){
            int n = q.size();
            int prevFresh = fresh;

            while(n--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for(auto& it : dir){
                    int row = i + it[0];
                    int col = j + it[1];

                    if(row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size()
                       && grid[row][col] == 1){
                        q.push({row, col});
                        grid[row][col] = 2;
                        fresh--;
                    }
                }
            }

            // If any fresh orange rotted in this level, increment time
            if(fresh != prevFresh){
                count++;
            }
        }

        if(fresh != 0){
            return -1;
        }

        return count;
    }
};

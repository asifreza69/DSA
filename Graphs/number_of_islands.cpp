// LeetCode 200: Number of Islands
// Approach: Use DFS to traverse and mark all connected land cells as visited.
//           Each DFS call represents one island.
// Time Complexity: O(m * n)
// Space Complexity: O(m * n)   (due to recursion stack)

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> dir{{0,-1}, {0,1}, {-1,0}, {1,0}};

    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != '1'){
            return;
        }

        // Mark current cell as visited
        grid[i][j] = '$';

        // Visit all 4 adjacent cells
        for(auto &it : dir){
            int row = i + it[0];
            int col = j + it[1];
            dfs(grid, row, col);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};

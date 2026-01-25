// LeetCode 695: Max Area of Island
// Approach: Use DFS to explore each island and count its area.
//           Track the maximum area found among all islands.
// Time Complexity: O(m * n)
// Space Complexity: O(m * n)   (due to recursion stack)

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> dir{{0,-1}, {0,1}, {-1,0}, {1,0}};

    void dfs(vector<vector<int>>& grid, int i, int j, int& count){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1){
            return;
        }

        // Mark current cell as visited and increase area count
        grid[i][j] = -1;
        count++;

        // Explore all 4 directions
        for(auto &it : dir){
            int row = i + it[0];
            int col = j + it[1];
            dfs(grid, row, col, count);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int count = 0;
        int ans = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    count = 0;
                    dfs(grid, i, j, count);
                    ans = max(ans, count);
                }
            }
        }
        return ans;
    }
};

// LeetCode 2658: Maximum Number of Fish in a Grid
// Approach: Use DFS to traverse each connected water component and sum all fish values.
//           Track the maximum sum obtained from any connected component.
// Time Complexity: O(m * n)
// Space Complexity: O(m * n)   (due to recursion stack)

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int sum = 0;
    vector<vector<int>> dir{{0,1}, {1,0}, {-1,0}, {0,-1}};

    int dfs(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0){
            return 0;
        }

        int t = grid[i][j];
        grid[i][j] = 0;     // Mark as visited
        sum += t;

        // Explore all 4 directions
        for(auto it : dir){
            int row = i + it[0];
            int col = j + it[1];
            dfs(grid, row, col);
        }

        return sum;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] > 0){
                    sum = 0;
                    int temp = dfs(grid, i, j);
                    ans = max(ans, temp);
                }
            }
        }
        return ans;
    }
};

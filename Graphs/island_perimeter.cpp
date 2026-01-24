// LeetCode 463: Island Perimeter
// Approach: Traverse each land cell and check its four neighbors; if neighbor is water or out of bounds, increment perimeter
// Time Complexity: O(m * n)
// Space Complexity: O(1)

#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, int &perimeter){
        vector<vector<int>> direction{{0,-1}, {0,1}, {-1,0}, {1,0}};
        for(auto it : direction){
            int new_x = i + it[0];
            int new_y = j + it[1];
            if(new_x < 0 || new_x >= grid.size() || new_y < 0 || new_y >= grid[0].size() || grid[new_x][new_y] == 0){
                perimeter++;
            }
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    dfs(i, j, grid, perimeter);
                }
            }
        }
        return perimeter;
    }
};

// LeetCode 1905: Count Sub Islands
// Approach: Use DFS on grid2 to explore each island and verify whether
//           all its cells are also land in grid1.
//           If any cell of the island lies on water in grid1, it is not a sub-island.
// Time Complexity: O(m * n)
// Space Complexity: O(m * n)   (due to recursion stack)

#include <vector>
using namespace std;

class Solution {
public:
    bool dfs(int i, int j, vector<vector<int>>& g1, vector<vector<int>>& g2){
        vector<vector<int>> dir{{0,1}, {1,0}, {-1,0}, {0,-1}};
        g2[i][j] = 0;   // Mark visited

        bool flag = true;

        for(auto& it : dir){
            int row = i + it[0];
            int col = j + it[1];

            if(row >= 0 && col >= 0 && row < g2.size() && col < g2[0].size() && g2[row][col] == 1){
                if(g1[row][col] == 0){
                    flag = false;
                }
                else{
                    g2[row][col] = 0;
                    if(!dfs(row, col, g1, g2)){
                        flag = false;
                    }
                }
            }
        }
        return flag;
    }

    int countSubIslands(vector<vector<int>>& g1, vector<vector<int>>& g2) {
        int count = 0;

        for(int i = 0; i < g2.size(); i++){
            for(int j = 0; j < g2[0].size(); j++){
                if(g1[i][j] == 1 && g2[i][j] == 1){
                    if(dfs(i, j, g1, g2)){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};

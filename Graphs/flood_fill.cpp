// LeetCode 733: Flood Fill
// Approach: Use DFS to recolor all connected pixels having the same base color
// Time Complexity: O(m * n)
// Space Complexity: O(m * n)   (due to recursion stack and auxiliary matrix)

#include <vector>
using namespace std;

class Solution {
public:
    int m, n;
    vector<vector<int>> direction{{0,-1}, {0,1}, {-1,0}, {1,0}};

    void dfs(vector<vector<int>>& ans, vector<vector<int>>& image, int sr, int sc, int base, int color){
        ans[sr][sc] = color;

        for(auto& it : direction){
            int row = sr + it[0];
            int col = sc + it[1];

            if(row >= 0 && row < m && col >= 0 && col < n &&
               image[row][col] == base && ans[row][col] != color){
                dfs(ans, image, row, col, base, color);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();

        vector<vector<int>> ans(m, vector<int>(n, -1));
        int base = image[sr][sc];

        // Avoid infinite loop if base color is already equal to new color
        if(base != color){
            dfs(ans, image, sr, sc, base, color);
        }

        // Fill remaining cells with original values
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(ans[i][j] == -1){
                    ans[i][j] = image[i][j];
                }
            }
        }
        return ans;
    }
};

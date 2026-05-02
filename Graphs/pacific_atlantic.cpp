#include <vector>
using namespace std;

class Solution {
public:
    int m, n;

    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& heights){
        vis[i][j] = 1;

        vector<vector<int>> dir{{1,0},{0,1},{-1,0},{0,-1}};

        for(auto& d : dir){
            int x = i + d[0];
            int y = j + d[1];

            if(x >= 0 && y >= 0 && x < m && y < n &&
               vis[x][y] == 0 &&
               heights[i][j] <= heights[x][y]){

                dfs(x, y, vis, heights);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));

        // Pacific (top row + left col)
        for(int i = 0; i < m; i++){
            dfs(i, 0, pacific, heights);
            dfs(i, n-1, atlantic, heights);
        }

        for(int j = 0; j < n; j++){
            dfs(0, j, pacific, heights);
            dfs(m-1, j, atlantic, heights);
        }

        vector<vector<int>> ans;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};

/*
==========================
🔥 APPROACH EXPLAINED
==========================

Key Trick:
❌ Water flow simulate mat karo (hard)
✅ Reverse thinking use karo

--------------------------------

🌊 Idea:

- Pacific touches:
  → top row + left column

- Atlantic touches:
  → bottom row + right column

--------------------------------

🔁 Reverse DFS:

Instead of going from cell → ocean,
go from ocean → cells

Condition:
You can move if:
heights[next] >= heights[current]

--------------------------------

Steps:

1. Run DFS from:
   - Pacific borders → mark reachable cells
   - Atlantic borders → mark reachable cells

2. Cells reachable from BOTH → answer

--------------------------------

Time Complexity: O(m * n)
Space Complexity: O(m * n)

--------------------------------

🧠 Interview One-Liner:

"Use reverse DFS from ocean boundaries to find common reachable cells"

*/

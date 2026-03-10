// LeetCode 62: Unique Paths
//
// Approach: Bottom-Up Dynamic Programming
//
// Idea:
// - A robot starts at the top-left corner (0,0) of an m x n grid
//   and wants to reach the bottom-right corner (m-1,n-1).
//
// - The robot can only move:
//      Right  → (i, j+1)
//      Down   → (i+1, j)
//
// - Let dp[i][j] represent the number of ways to reach cell (i,j).
//
// - Recurrence relation:
//      dp[i][j] = dp[i-1][j] + dp[i][j-1]
//
// - Base cases:
//      First row → only one way (move right)
//      First column → only one way (move down)
//
// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

int uniquePaths(int m, int n) {
        vector<vector<int>>t(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0){
                    t[i][j]=1;
                }
                else{
                    t[i][j]=t[i-1][j]+t[i][j-1];
                }
            }
        }
        return t[m-1][n-1];
    }

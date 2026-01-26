// LeetCode 130: Surrounded Regions
// Approach: Perform DFS from all boundary 'O' cells and mark them as safe.
//           Convert remaining 'O' cells to 'X' and restore safe cells back to 'O'.
// Time Complexity: O(m * n)
// Space Complexity: O(m * n)   (due to recursion stack)

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> dir{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    void dfs(int i, int j, vector<vector<char>>& b) {
        if (i < 0 || j < 0 || i >= b.size() || j >= b[0].size() || b[i][j] != 'O')
            return;

        // Mark boundary connected 'O' as safe
        b[i][j] = '#';

        for (auto& d : dir) {
            dfs(i + d[0], j + d[1], b);
        }
    }

    void solve(vector<vector<char>>& b) {
        int n = b.size(), m = b[0].size();

        // Run DFS for boundary rows
        for (int i = 0; i < n; i++) {
            if (b[i][0] == 'O')
                dfs(i, 0, b);
            if (b[i][m - 1] == 'O')
                dfs(i, m - 1, b);
        }

        // Run DFS for boundary columns
        for (int j = 0; j < m; j++) {
            if (b[0][j] == 'O')
                dfs(0, j, b);
            if (b[n - 1][j] == 'O')
                dfs(n - 1, j, b);
        }

        // Flip surrounded regions and restore safe cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (b[i][j] == 'O')
                    b[i][j] = 'X';
                else if (b[i][j] == '#')
                    b[i][j] = 'O';
            }
        }
    }
};

// LeetCode 1267: Count Servers that Communicate
// Approach: Count number of servers in each row and column.
//           A server can communicate if its row or column has more than one server.
// Time Complexity: O(m * n)
// Space Complexity: O(m + n)

#include <vector>
using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        vector<int> row(m, 0), col(n, 0);

        // Count servers in each row and column
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                }
            }
        }

        // Count servers that can communicate
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && (row[i] > 1 || col[j] > 1)) {
                    count++;
                }
            }
        }

        return count;
    }
};

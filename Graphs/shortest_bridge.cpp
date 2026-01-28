// LeetCode 934: Shortest Bridge
// Approach:
// 1) Find the first island using DFS and mark all its cells as visited.
// 2) Push all visited cells into a queue.
// 3) Perform multi-source BFS from the first island until we reach
//    any cell of the second island.
// 4) The BFS level represents the minimum number of water cells to flip.
//
// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    int m, n;

    // Directions: down, right, up, left
    vector<vector<int>> dir{{1,0},{0,1},{-1,0},{0,-1}};

    // DFS to mark the first island
    void dfs(int i, int j, vector<vector<int>>& grid,
             set<pair<int,int>>& visited) {

        if (i < 0 || i >= m || j < 0 || j >= n ||
            visited.count({i, j}) || grid[i][j] == 0) {
            return;
        }

        visited.insert({i, j});

        for (auto& d : dir) {
            int ni = i + d[0];
            int nj = j + d[1];
            dfs(ni, nj, grid, visited);
        }
    }

    // BFS to expand from first island and reach second island
    int bfs(vector<vector<int>>& grid, set<pair<int,int>>& visited) {
        int level = 0;
        queue<pair<int,int>> q;

        // Multi-source BFS initialization
        for (auto& cell : visited) {
            q.push(cell);
        }

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [x, y] = q.front();
                q.pop();

                for (auto& d : dir) {
                    int nx = x + d[0];
                    int ny = y + d[1];

                    if (nx >= 0 && ny >= 0 && nx < m && ny < n &&
                        !visited.count({nx, ny})) {

                        // If we reach the second island
                        if (grid[nx][ny] == 1) {
                            return level;
                        }

                        visited.insert({nx, ny});
                        q.push({nx, ny});
                    }
                }
            }
            level++;
        }
        return level;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        set<pair<int,int>> visited;

        // Find first island and start DFS
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(i, j, grid, visited);
                    return bfs(grid, visited);
                }
            }
        }
        return -1;
    }
};

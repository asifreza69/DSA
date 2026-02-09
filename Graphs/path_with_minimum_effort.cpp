// LeetCode 1631: Path With Minimum Effort
//
// Approach: Dijkstra's Algorithm (Minimax Path)
//
// Explanation:
// - Each cell is a node in a graph
// - Edge weight between two adjacent cells is the absolute height difference
// - The effort of a path is defined as the maximum edge weight along that path
// - We want to minimize this maximum effort
//
// This is a classic "minimize the maximum edge" problem,
// which can be solved using Dijkstra’s Algorithm
//
// Key Idea:
// - Instead of summing distances, we track the maximum difference so far
// - For each move:
//     newEffort = max(currentEffort, abs(height difference))
// - If newEffort is smaller, update and push into priority queue
//
// Time Complexity:
// - O(m * n * log(m * n))
//
// Space Complexity:
// - O(m * n)

class Solution {
public:
    int m, n;

    // Check if cell is within grid boundaries
    bool isSafe(int x, int y) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }

    int minimumEffortPath(vector<vector<int>>& heights) {

        m = heights.size();
        n = heights[0].size();

        vector<vector<int>> directions{{-1,0},{1,0},{0,-1},{0,1}};

        // res[i][j] stores minimum effort required to reach cell (i, j)
        vector<vector<int>> res(m, vector<int>(n, INT_MAX));

        // Min-heap: {effort, {x, y}}
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        res[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            int diff = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            // Explore neighbors
            for (auto& d : directions) {
                int x_ = x + d[0];
                int y_ = y + d[1];

                if (isSafe(x_, y_)) {
                    int edgeDiff = abs(heights[x][y] - heights[x_][y_]);
                    int maxDiff = max(diff, edgeDiff);

                    // Relaxation step
                    if (maxDiff < res[x_][y_]) {
                        res[x_][y_] = maxDiff;
                        pq.push({maxDiff, {x_, y_}});
                    }
                }
            }
        }

        return res[m - 1][n - 1];
    }
};

// LeetCode 778: Swim in Rising Water
//
// Approach: Dijkstra’s Algorithm (Minimax Path)
//
// Idea:
// - Each cell has a height, representing the time when it becomes passable
// - We want to reach (n-1, n-1) with minimum possible maximum height on the path
// - This is a classic "minimize the maximum edge weight" problem
//
// Key Insight:
// - Instead of summing costs, the cost of a path is the maximum height encountered
// - Use Dijkstra where:
//   newTime = max(currentTime, grid[nextCell])
//
// Time Complexity:
// - O(n^2 log n)
//
// Space Complexity:
// - O(n^2)

class Solution {
public:
    // Directions: down, up, right, left
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    // {time, {row, col}}
    using P = pair<int, pair<int, int>>;

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        // result[i][j] = minimum time needed to reach cell (i, j)
        vector<vector<int>> result(n, vector<int>(n, INT_MAX));

        // Min-heap ordered by minimum time
        priority_queue<P, vector<P>, greater<P>> pq;

        // Start from (0,0)
        result[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});

        while (!pq.empty()) {
            int currTime = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            // Destination reached with minimum possible time
            if (i == n - 1 && j == n - 1)
                return currTime;

            // Skip outdated states
            if (currTime > result[i][j])
                continue;

            // Explore neighbors
            for (auto& dir : directions) {
                int ni = i + dir[0];
                int nj = j + dir[1];

                if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                    int nextTime = max(currTime, grid[ni][nj]);

                    if (nextTime < result[ni][nj]) {
                        result[ni][nj] = nextTime;
                        pq.push({nextTime, {ni, nj}});
                    }
                }
            }
        }

        return -1; // Unreachable (never happens as per problem constraints)
    }
};

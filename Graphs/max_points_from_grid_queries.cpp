// LeetCode 2503: Maximum Number of Points From Grid Queries
//
// Approach:
// Offline Queries + Min-Heap (Dijkstra-style BFS)
//
// Idea:
// 1. Sort queries in ascending order so we can process them efficiently.
// 2. Use a min-heap to always expand the cell with the smallest value first.
// 3. Start from (0,0) and keep visiting cells whose value is < current query.
// 4. Maintain a global count of how many cells are reachable so far.
// 5. Store results using original query indices.
//
// Key Observations:
// - Each cell is visited only once.
// - Count only increases as queries increase.
//
// Time Complexity:
// O((m * n) log(m * n) + q log q)
//
// Space Complexity:
// O(m * n + q)

class Solution {
public:
    // Directions: down, right, up, left
    vector<vector<int>> dir{{1,0},{0,1},{-1,0},{0,-1}};

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {

        int m = grid.size();
        int n = grid[0].size();

        // Store queries with original indices
        vector<pair<int,int>> sortedQuery;
        for (int i = 0; i < queries.size(); i++) {
            sortedQuery.push_back({queries[i], i});
        }

        // Sort queries by value
        sort(sortedQuery.begin(), sortedQuery.end());

        // Min-heap: {cell value, row, col}
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;

        vector<int> ans(queries.size(), 0);
        int count = 0;

        // Process queries in increasing order
        for (auto& q : sortedQuery) {

            int queryValue = q.first;
            int queryIndex = q.second;

            // Expand reachable cells with value < queryValue
            while (!pq.empty() && pq.top()[0] < queryValue) {

                int x = pq.top()[1];
                int y = pq.top()[2];
                pq.pop();

                count++;

                for (auto& d : dir) {
                    int nx = x + d[0];
                    int ny = y + d[1];

                    if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny]) {
                        pq.push({grid[nx][ny], nx, ny});
                        visited[nx][ny] = true;
                    }
                }
            }

            // Store result for original query index
            ans[queryIndex] = count;
        }

        return ans;
    }
};

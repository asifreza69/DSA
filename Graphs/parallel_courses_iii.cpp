// LeetCode 2050: Parallel Courses III
//
// Approach: Topological Sort + Dynamic Programming
//
// Explanation:
// - Courses form a Directed Acyclic Graph (DAG)
// - Each course has a completion time
// - A course can start only after all its prerequisites are finished
// - We want the minimum time to finish all courses
//
// Idea:
// - Use Kahn’s Algorithm (BFS-based Topological Sort)
// - Track indegree of each course
// - Maintain a `finish` array where:
//     finish[i] = earliest time at which course i can be completed
// - For each edge u -> v:
//     finish[v] = max(finish[v], finish[u] + time[v])
//
// This ensures v starts only after all prerequisites are completed
//
// Time Complexity:
// - O(n + m), where m = number of relations
//
// Space Complexity:
// - O(n + m)

class Solution {
public:
    int minimumTime(int n,
                    vector<vector<int>>& relations,
                    vector<int>& time) {

        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);

        // Build graph and indegree array
        for (auto &e : relations) {
            adj[e[0] - 1].push_back(e[1] - 1);
            indegree[e[1] - 1]++;
        }

        queue<int> q;
        vector<int> finish(n, 0);  // Finish time of each course

        // Courses with no prerequisites can start immediately
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                finish[i] = time[i];
            }
        }

        // Topological BFS
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto &v : adj[u]) {

                // DP transition:
                // Earliest finish time for course v
                finish[v] = max(finish[v], finish[u] + time[v]);

                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // Total time = maximum finish time
        return *max_element(finish.begin(), finish.end());
    }
};

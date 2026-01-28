// LeetCode 1462: Course Schedule IV
// Approach: Use Topological Sort (Kahn’s Algorithm) and maintain a set of prerequisites
//           for each course. While processing edges, propagate prerequisite information.
//           Answer each query by checking whether src exists in dest's prerequisite set.
// Time Complexity: O(V * (V + E))   (worst case due to set propagation)
// Space Complexity: O(V * V)

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);

        // Build graph and indegree array
        for (auto &edge : prerequisites) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> que;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                que.push(i);
            }
        }

        // Map storing prerequisites for each course
        unordered_map<int, unordered_set<int>> mp;

        // Topological BFS
        while (!que.empty()) {
            int node = que.front();
            que.pop();

            for (auto &ngbr : adj[node]) {
                // Insert direct prerequisite
                mp[ngbr].insert(node);

                // Insert all indirect prerequisites
                for (auto &prereq : mp[node]) {
                    mp[ngbr].insert(prereq);
                }

                indegree[ngbr]--;
                if (indegree[ngbr] == 0) {
                    que.push(ngbr);
                }
            }
        }

        int Q = queries.size();
        vector<bool> result(Q, false);

        // Answer queries
        for (int i = 0; i < Q; i++) {
            int src  = queries[i][0];
            int dest = queries[i][1];
            result[i] = mp[dest].contains(src);
        }

        return result;
    }
};

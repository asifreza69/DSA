class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {

        unordered_map<int, vector<int>> mp;
        vector<int> indegree(n, 0);

        // Build graph
        // prerequisite -> course
        for(auto &it : p) {
            int u = it[0]; // course
            int v = it[1]; // prerequisite

            mp[v].push_back(u);
            indegree[u]++;
        }

        queue<int> q;

        // Push all nodes with indegree 0
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        // Kahn's Algorithm
        while(!q.empty()) {

            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(auto nei : mp[node]) {
                indegree[nei]--;

                if(indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        // If all courses processed → no cycle
        return ans.size() == n;
    }
};

/*
==========================
🔥 COURSE SCHEDULE
==========================

Goal:
Check if all courses can be completed.

--------------------------------

🧠 Core Idea:

Courses can be finished only if
the dependency graph has NO cycle.

--------------------------------

Approach:
Topological Sort (Kahn's Algorithm)

--------------------------------

Logic:

1. Build graph:
   prerequisite -> course

2. Compute indegree

3. Push indegree 0 nodes

4. Perform BFS

5. If processed nodes == n
   → possible to finish all courses

--------------------------------

Cycle Condition:

If topological ordering contains
fewer than n nodes,
cycle exists.

--------------------------------

⏱️ Time Complexity:
O(V + E)

--------------------------------

🧠 Space Complexity:
O(V + E)

--------------------------------

🧩 Pattern:
Topological Sort + Cycle Detection

--------------------------------

🎯 Category:
Graph → DAG → Topological Sort

--------------------------------

🧠 Interview One-Liner:

Use Kahn's Algorithm to detect cycle.
If all nodes are processed,
all courses can be completed.

*/

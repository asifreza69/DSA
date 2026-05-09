class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>> &edges) {

        // indegree of each node
        vector<int> indegree(V, 0);

        // adjacency list
        unordered_map<int, vector<int>> mp;

        // build graph
        for(auto &it : edges) {
            mp[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        queue<int> q;
        vector<int> ans;

        // push all nodes with indegree 0
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                ans.push_back(i);
            }
        }

        // BFS
        while(!q.empty()) {

            int node = q.front();
            q.pop();

            for(auto nei : mp[node]) {

                indegree[nei]--;

                if(indegree[nei] == 0) {
                    q.push(nei);
                    ans.push_back(nei);
                }
            }
        }

        return ans;
    }
};

/*
==========================
🔥 TOPOLOGICAL SORT
(KAHN'S ALGORITHM)
==========================

Goal:
Return linear ordering of nodes
such that u appears before v
for every directed edge u → v

--------------------------------

🧠 Core Idea:

Nodes with indegree 0 can be
processed first.

After removing them,
new nodes may become indegree 0.

--------------------------------

Algorithm:

1. Compute indegree of all nodes
2. Push indegree 0 nodes into queue
3. Pop node and add to answer
4. Decrease indegree of neighbours
5. Push neighbours whose indegree becomes 0

--------------------------------

⏱️ Time Complexity:
O(V + E)

--------------------------------

🧠 Space Complexity:
O(V + E)

--------------------------------

🧩 Pattern:
BFS + Indegree

--------------------------------

🎯 Category:
Graph → DAG → Topological Sort

--------------------------------

✅ Works Only On:
Directed Acyclic Graph (DAG)

--------------------------------

🧠 Interview One-Liner:

Use BFS on all indegree 0 nodes,
removing dependencies level by level.

*/

class Solution {
public:

    void dfs(int node,
             unordered_map<int, vector<int>>& mp,
             vector<bool>& visited) {

        visited[node] = true;

        for(auto nei : mp[node]) {
            if(!visited[nei]) {
                dfs(nei, mp, visited);
            }
        }
    }

    int isCircle(vector<string> &arr) {

        vector<int> indegree(26, 0);
        vector<int> outdegree(26, 0);

        unordered_map<int, vector<int>> mp;

        // Build graph:
        // first character -> last character
        for(auto &s : arr) {

            int u = s.front() - 'a';
            int v = s.back()  - 'a';

            mp[u].push_back(v);

            outdegree[u]++;
            indegree[v]++;
        }

        // Condition 1:
        // indegree must equal outdegree
        for(int i = 0; i < 26; i++) {
            if(indegree[i] != outdegree[i]) {
                return 0;
            }
        }

        // Find starting node
        int start = -1;
        for(int i = 0; i < 26; i++) {
            if(outdegree[i] > 0) {
                start = i;
                break;
            }
        }

        // No edges → valid circle
        if(start == -1) return 1;

        // DFS to check connectivity
        vector<bool> visited(26, false);
        dfs(start, mp, visited);

        // Condition 2:
        // all nodes with edges must be visited
        for(int i = 0; i < 26; i++) {
            if((indegree[i] > 0 || outdegree[i] > 0)
               && !visited[i]) {
                return 0;
            }
        }

        return 1;
    }
};

/*
==========================
🔥 CIRCLE OF STRINGS
==========================

Goal:
Check if all strings can be arranged
in a circle such that:

last char of current string
= first char of next string

--------------------------------

🧠 Core Idea:

Convert strings into a directed graph:

first character → last character

Then check if graph has
an Eulerian Cycle.

--------------------------------

Conditions for Eulerian Cycle:

1. indegree[node] == outdegree[node]
   for every node

2. All nodes having edges
   belong to one connected component

--------------------------------

Example:

"abc" → a → c
"cda" → c → a

Forms a cycle.

--------------------------------

⏱️ Time Complexity:
O(N + 26)

where N = number of strings

--------------------------------

🧠 Space Complexity:
O(N)

--------------------------------

🧩 Pattern:
Eulerian Cycle in Directed Graph

--------------------------------

🎯 Category:
Graph → Euler Path/Cycle

--------------------------------

🧠 Interview One-Liner:

Model each string as an edge from
first letter to last letter and
check Eulerian cycle conditions.

*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  
    bool dfs(int node,
             unordered_map<int, vector<int>>& adj,
             vector<bool>& visited,
             vector<bool>& inRecursion){

        visited[node] = true;
        inRecursion[node] = true;

        for(auto nei : adj[node]){

            // Case 1: already in recursion → cycle
            if(visited[nei] && inRecursion[nei]){
                return true;
            }

            // Case 2: not visited → DFS
            else if(!visited[nei] && dfs(nei, adj, visited, inRecursion)){
                return true;
            }
        }

        // backtrack
        inRecursion[node] = false;
        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &edges) {

        unordered_map<int, vector<int>> adj;

        // build graph
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
        }

        vector<bool> visited(V, false);
        vector<bool> inRecursion(V, false);

        // check each component
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                if(dfs(i, adj, visited, inRecursion)){
                    return true;
                }
            }
        }

        return false;
    }
};

/*
==========================
🔥 APPROACH EXPLAINED
==========================

Goal:
Detect cycle in directed graph

--------------------------------

🧠 Core Idea:
Use DFS + recursion stack

--------------------------------

visited[node] → node visited ever
inRecursion[node] → node in current DFS path

--------------------------------

Cycle Condition:
if(visited && inRecursion) → cycle (back edge)

--------------------------------

Example:
0 → 1 → 2 → 0
→ revisiting node in same path → cycle

--------------------------------

⏱️ Time Complexity:
O(V + E)

🧠 Space Complexity:
O(V)

--------------------------------

🧩 Pattern:
DFS + Recursion Stack (Back Edge Detection)

--------------------------------

🎯 Category:
Graph → DFS → Cycle Detection → Directed Graph

--------------------------------

🧠 Interview One-Liner:
Use DFS with recursion stack to detect back edges in directed graph

*/

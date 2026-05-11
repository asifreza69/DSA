class Solution {
public:

    int count = 0;

    void dfs(int node, int dest, vector<int> adj[]) {

        // Destination reached
        if(node == dest) {
            count++;
            return;
        }

        // Explore all outgoing edges
        for(auto nei : adj[node]) {
            dfs(nei, dest, adj);
        }
    }

    int countPaths(int V, vector<int> adj[], int s, int d) {

        count = 0;

        dfs(s, d, adj);

        return count;
    }
};

/*
==========================
🔥 COUNT ALL POSSIBLE PATHS
==========================

Goal:
Count total number of distinct paths
from source s to destination d.

--------------------------------

🧠 Core Idea:

Use DFS.

Every time destination is reached,
increment global counter.

--------------------------------

Algorithm:

1. Start DFS from source.
2. If current node == destination:
      count++
3. Recursively explore all neighbours.

--------------------------------

⚠️ Important Assumption:
This approach works when the graph
does not contain cycles in a way that
creates infinite paths (typically DAG).

--------------------------------

Example:

0 → 1 → 3
 \      ^
  → 2 --|

Paths from 0 to 3:
0→1→3
0→2→3

Answer = 2

--------------------------------

⏱️ Time Complexity:
O(number of possible paths)

Worst case can be exponential.

--------------------------------

🧠 Space Complexity:
O(path length)
(recursion stack)

--------------------------------

🧩 Pattern:
DFS + Backtracking

--------------------------------

🎯 Category:
Graph → DFS → Path Counting

--------------------------------

🧠 Interview One-Liner:

Run DFS from source and increment
counter every time destination
is reached.

*/

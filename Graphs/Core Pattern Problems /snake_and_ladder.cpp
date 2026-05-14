class Solution {
public:
    int minThrow(int N, int arr[]) {

        // Mapping:
        // snake or ladder start -> destination
        unordered_map<int, int> mpp;

        for(int i = 1; i < 2 * N; i += 2) {
            mpp[arr[i - 1]] = arr[i];
        }

        // Visited cells (1 to 30)
        vector<int> vis(31, 0);

        queue<int> q;

        // Start from cell 1
        q.push(1);
        vis[1] = 1;

        int throws = 0;

        // BFS
        while(!q.empty()) {

            int sz = q.size();
            throws++;

            while(sz--) {

                int node = q.front();
                q.pop();

                // Try dice values 1..6
                for(int dice = 1;
                    dice <= 6 &&
                    node + dice <= 30;
                    dice++) {

                    int next = node + dice;

                    // Apply snake or ladder
                    if(mpp.count(next)) {
                        next = mpp[next];
                    }

                    if(!vis[next]) {

                        // Destination reached
                        if(next == 30) {
                            return throws;
                        }

                        vis[next] = 1;
                        q.push(next);
                    }
                }
            }
        }

        return -1;
    }
};

/*
==========================
🔥 SNAKE AND LADDER
==========================

Goal:
Find minimum dice throws needed
to reach square 30.

--------------------------------

🧠 Core Idea:

Each board cell is a graph node.

From a cell, you can move to
cell + 1 ... cell + 6.

If a square contains a snake
or ladder, jump immediately
to its destination.

All edges have equal weight,
so shortest path = BFS.

--------------------------------

Algorithm:

1. Store snake/ladder mapping.
2. Start BFS from cell 1.
3. For each cell, try dice
   values 1 to 6.
4. Apply snake/ladder jump.
5. First time reaching 30
   gives minimum throws.

--------------------------------

Why BFS?

Every dice throw has equal cost
(1 move), so BFS guarantees
minimum number of throws.

--------------------------------

Example:

1 -> 2 -> 15 (ladder)

This still counts as one throw.

--------------------------------

⏱️ Time Complexity:
O(30 * 6) ≈ O(1)

Generalized board:
O(V + E)

--------------------------------

🧠 Space Complexity:
O(30)

--------------------------------

🧩 Pattern:
Shortest Path in Unweighted Graph

--------------------------------

🎯 Category:
Graph → BFS

--------------------------------

🧠 Interview One-Liner:

Treat each square as a node and
use BFS where each level
represents one dice throw.

*/

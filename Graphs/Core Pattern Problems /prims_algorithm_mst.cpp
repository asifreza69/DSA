class Solution {
public:

    int spanningTree(int V, vector<vector<int>>& edges) {

        // Adjacency List
        unordered_map<int, vector<pair<int,int>>> mp;

        for(auto it : edges){

            int u = it[0];
            int v = it[1];
            int wt = it[2];

            mp[u].push_back({v, wt});
            mp[v].push_back({u, wt});
        }

        vector<bool> visited(V, false);

        // {weight, node}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        pq.push({0,0});

        int sum = 0;

        while(!pq.empty()){

            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // skip already visited node
            if(visited[node]) continue;

            visited[node] = true;

            sum += wt;

            // explore neighbours
            for(auto it : mp[node]){

                int nei = it.first;
                int nwt = it.second;

                if(!visited[nei]){
                    pq.push({nwt, nei});
                }
            }
        }

        return sum;
    }
};

/*
==========================
🔥 PRIM'S ALGORITHM
==========================

Goal:
Find Minimum Spanning Tree (MST)

--------------------------------

🧠 Core Idea:

Always take minimum weight edge
connected to current MST

--------------------------------

Algorithm:

1. Start from any node
2. Push all neighbours into min-heap
3. Pick minimum edge
4. If node not visited:
      include in MST
5. Repeat

--------------------------------

🧠 Data Structures:
- Min Heap (Priority Queue)
- Visited Array

--------------------------------

⏱️ Time Complexity:
O(E log V)

--------------------------------

🧠 Space Complexity:
O(V + E)

--------------------------------

🧩 Pattern:
Greedy + Heap

--------------------------------

🎯 Category:
Graph → MST → Prim's Algorithm

--------------------------------

🧠 Interview One-Liner:

Use a min-heap to greedily expand MST
by always choosing minimum weight edge

*/

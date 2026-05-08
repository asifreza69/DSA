class Solution {
public:

    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {

        // adjacency list
        unordered_map<int, vector<pair<int,int>>> mp;

        for(auto &it : edges){

            int u = it[0];
            int v = it[1];
            int wt = it[2];

            mp[u].push_back({v, wt});
            mp[v].push_back({u, wt});
        }

        // {distance, node}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        pq.push({0, src});

        vector<int> dist(V, INT_MAX);

        dist[src] = 0;

        while(!pq.empty()){

            int node = pq.top().second;
            int wt = pq.top().first;

            pq.pop();

            for(auto &it : mp[node]){

                int nei = it.first;
                int nwt = it.second;

                // relaxation
                if(wt + nwt < dist[nei]){

                    dist[nei] = wt + nwt;

                    pq.push({dist[nei], nei});
                }
            }
        }

        return dist;
    }
};

/*
==========================
🔥 DIJKSTRA ALGORITHM
==========================

Goal:
Find shortest distance from source
to all nodes

--------------------------------

🧠 Core Idea:

Always process node with
minimum current distance first

--------------------------------

Algorithm:

1. Push source in min-heap
2. Pop minimum distance node
3. Relax all neighbours
4. Update shorter distance if possible

--------------------------------

🧠 Relaxation:

if(dist[node] + weight < dist[nei])
    update distance

--------------------------------

🧠 Data Structures:
- Min Heap (Priority Queue)
- Distance Array

--------------------------------

⏱️ Time Complexity:
O(E log V)

--------------------------------

🧠 Space Complexity:
O(V + E)

--------------------------------

🧩 Pattern:
Greedy + Heap + Shortest Path

--------------------------------

🎯 Category:
Graph → Shortest Path → Dijkstra

--------------------------------

⚠️ Limitation:
Does NOT work for negative weights

--------------------------------

🧠 Interview One-Liner:

Use min-heap to greedily process
the node with smallest distance first

*/

// User function Template for C++

class Solution {
public:
    
    vector<int> parent;
    vector<int> rank;

    // Find with Path Compression
    int find(int x){
        if(parent[x] == x){
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    // Union by Rank
    void Union(int x, int y){

        int xparent = find(x);
        int yparent = find(y);

        if(xparent == yparent){
            return;
        }

        if(rank[xparent] > rank[yparent]){
            parent[yparent] = xparent;
        }
        else if(rank[xparent] < rank[yparent]){
            parent[xparent] = yparent;
        }
        else{
            parent[xparent] = yparent;
            rank[yparent]++;
        }
    }

    // Kruskal Algorithm
    int krusk(vector<vector<int>>& vec){

        int sum = 0;

        for(auto it : vec){

            int u = it[0];
            int v = it[1];
            int wt = it[2];

            int parentu = find(u);
            int parentv = find(v);

            // take edge only if no cycle forms
            if(parentu != parentv){

                Union(u, v);
                sum += wt;
            }
        }

        return sum;
    }

    int kruskalsMST(int V, vector<vector<int>> &edges) {

        rank.resize(V, 0);
        parent.resize(V);

        for(int i = 0; i < V; i++){
            parent[i] = i;
        }

        vector<vector<int>> vec;

        // store edges
        for(auto it : edges){

            int u = it[0];
            int v = it[1];
            int wt = it[2];

            vec.push_back({u, v, wt});
        }

        // sort by weight
        auto comparator = [&](vector<int>& a, vector<int>& b){
            return a[2] < b[2];
        };

        sort(vec.begin(), vec.end(), comparator);

        return krusk(vec);
    }
};

/*
==========================
🔥 KRUSKAL'S ALGORITHM
==========================

Goal:
Find Minimum Spanning Tree (MST)

--------------------------------

🧠 Core Idea:

Take smallest edge first
while avoiding cycles

--------------------------------

Algorithm:

1. Sort all edges by weight
2. Traverse edges:
   - if edge forms NO cycle
       → include it
   - otherwise skip

--------------------------------

🧠 Cycle Detection:
Use DSU / Union Find

--------------------------------

⏱️ Time Complexity:
O(E log E)

(E log E for sorting)

--------------------------------

🧠 Space Complexity:
O(V)

--------------------------------

🧩 Pattern:
Greedy + DSU (Union Find)

--------------------------------

🎯 Category:
Graph → MST → Kruskal Algorithm

--------------------------------

🧠 Interview One-Liner:

Sort edges by weight and use DSU
to greedily build MST without cycles

*/

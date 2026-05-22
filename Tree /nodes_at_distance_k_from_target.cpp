/* A binary Tree node
struct Node {
    int data;
    struct Node *left, *right;
};
*/

class Solution {
public:

    // Convert tree into undirected graph
    void makegraph(
        Node* root,
        unordered_map<int, vector<int>>& adj
    ) {

        if(root == NULL) {
            return;
        }

        if(root->left != NULL) {

            adj[root->data]
                .push_back(root->left->data);

            adj[root->left->data]
                .push_back(root->data);
        }

        if(root->right != NULL) {

            adj[root->data]
                .push_back(root->right->data);

            adj[root->right->data]
                .push_back(root->data);
        }

        makegraph(root->left, adj);
        makegraph(root->right, adj);
    }

    vector<int> KDistanceNodes(
        Node* root,
        int target,
        int k
    ) {

        unordered_map<int, vector<int>> adj;

        // Tree -> Graph
        makegraph(root, adj);

        queue<int> q;
        unordered_set<int> visited;

        q.push(target);
        visited.insert(target);

        vector<int> ans;

        // BFS level by level
        while(!q.empty() && k > 0) {

            int sz = q.size();

            k--;

            while(sz--) {

                int node = q.front();
                q.pop();

                for(auto nei : adj[node]) {

                    if(visited.find(nei)
                       == visited.end()) {

                        visited.insert(nei);
                        q.push(nei);

                        if(k == 0) {
                            ans.push_back(nei);
                        }
                    }
                }
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};

/*
==========================
🔥 NODES AT DISTANCE K
FROM TARGET
==========================

Goal:

Find all nodes whose distance
from target node is exactly K.

--------------------------------

🧠 Core Idea:

Normal tree traversal allows:

Parent → Child

But distance K may require:

Child → Parent

So first convert tree into
an UNDIRECTED GRAPH.

--------------------------------

Step 1:

Convert:

        1
       / \
      2   3

Into:

1 ↔ 2
1 ↔ 3

--------------------------------

Step 2:

Start BFS from target node.

Each BFS level represents
distance +1.

--------------------------------

Step 3:

When level reaches K,
all nodes currently reached
are answer nodes.

--------------------------------

Example:

        1
       / \
      2   3
     / \
    4   5

Target = 2
K = 1

Answer:

[1,4,5]

--------------------------------

Why BFS?

Because BFS naturally explores
nodes level by level.

Distance = BFS Level

--------------------------------

⏱️ Time Complexity:

Graph Construction:
O(N)

BFS:
O(N)

Sorting:
O(M log M)

Overall:

O(N + M log M)

M = answer size

--------------------------------

🧠 Space Complexity:

Adjacency List:
O(N)

Queue:
O(N)

Visited:
O(N)

Overall:

O(N)

--------------------------------

🧩 Pattern:

Tree → Graph Conversion
+
Multi-Level BFS

--------------------------------

🎯 Category:

Binary Tree
Graph BFS

--------------------------------

🧠 Interview One-Liner:

Convert tree into an undirected
graph and perform BFS from the
target node to obtain all nodes
at distance K.

*/

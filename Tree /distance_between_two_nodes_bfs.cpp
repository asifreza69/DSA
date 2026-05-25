class Solution {
public:

    void makegraph(
        Node* root,
        unordered_map<int, vector<int>>& mp
    ) {
        if(root == NULL) {
            return;
        }

        if(root->left != NULL) {

            mp[root->data].push_back(
                root->left->data
            );

            mp[root->left->data].push_back(
                root->data
            );

            makegraph(root->left, mp);
        }

        if(root->right != NULL) {

            mp[root->data].push_back(
                root->right->data
            );

            mp[root->right->data].push_back(
                root->data
            );

            makegraph(root->right, mp);
        }
    }

    int findDist(Node* root,
                 int a,
                 int b) {

        if(a == b) {
            return 0;
        }

        unordered_map<int,
                      vector<int>> mp;

        makegraph(root, mp);

        queue<int> q;

        unordered_set<int> vis;

        q.push(a);

        vis.insert(a);

        int distance = 0;

        while(!q.empty()) {

            int size = q.size();

            distance++;

            while(size--) {

                int node =
                q.front();

                q.pop();

                for(auto nei : mp[node]) {

                    if(!vis.count(nei)) {

                        if(nei == b) {
                            return distance;
                        }

                        vis.insert(nei);

                        q.push(nei);
                    }
                }
            }
        }

        return -1;
    }
};

/*
=================================================
DISTANCE BETWEEN TWO NODES IN BINARY TREE
(Graph + BFS Approach)
=================================================

Problem:

Find the number of edges
between nodes a and b.

-------------------------------------------------

Example:

            1
          /   \
         2     3
              / \
             4   5

a = 2
b = 5

Path:

2 -> 1 -> 3 -> 5

Distance = 3

-------------------------------------------------

Core Idea:

A binary tree can be viewed
as an undirected graph.

Parent <-> Child

Once graph is built,
distance becomes a normal
shortest path problem.

-------------------------------------------------

Graph Construction:

For every edge:

parent ---- child

Store both directions.

Example:

1 <-> 2
1 <-> 3
3 <-> 4
3 <-> 5

-------------------------------------------------

Adjacency List:

1 : [2,3]

2 : [1]

3 : [1,4,5]

4 : [3]

5 : [3]

-------------------------------------------------

Why BFS?

BFS explores nodes
level by level.

The first time we reach
target node b, we are
guaranteed to have found
the shortest distance.

-------------------------------------------------

BFS Traversal:

Start from node a.

Level 0:

2

Level 1:

1

Level 2:

3

Level 3:

4,5

Found 5

Answer = 3

-------------------------------------------------

Distance Meaning:

Level Number
=
Number of edges travelled.

-------------------------------------------------

Complexity:

Graph Building:
O(N)

BFS:
O(N)

Total:
O(N)

-------------------------------------------------

Space Complexity:

Adjacency List:
O(N)

Queue:
O(N)

Visited:
O(N)

Total:
O(N)

-------------------------------------------------

Pattern:

Tree → Graph Conversion

Shortest Path BFS

-------------------------------------------------

Important Note:

This solution assumes
all node values are unique.

If duplicate values are
allowed, use:

unordered_map<Node*,
              vector<Node*>>

instead of using data values.

-------------------------------------------------

Interview One-Liner:

Convert the binary tree into
an undirected graph and run
BFS from node a; the BFS level
at which node b is reached is
the required distance.

=================================================
*/

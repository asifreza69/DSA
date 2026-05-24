/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
public:

    vector<vector<int>>
    verticalOrder(Node *root) {

        // hd -> nodes
        map<int, vector<int>> mp;

        queue<pair<Node*, int>> q;

        // root at hd = 0
        q.push({root, 0});

        while(!q.empty()) {

            auto curr = q.front();
            q.pop();

            Node* node = curr.first;
            int hd = curr.second;

            mp[hd].push_back(node->data);

            // left child
            if(node->left != NULL) {
                q.push({
                    node->left,
                    hd - 1
                });
            }

            // right child
            if(node->right != NULL) {
                q.push({
                    node->right,
                    hd + 1
                });
            }
        }

        vector<vector<int>> ans;

        for(auto &it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

/*
==========================
🔥 VERTICAL ORDER
TRAVERSAL
==========================

Goal:

Print nodes column by column
from leftmost vertical line
to rightmost vertical line.

--------------------------------

🧠 Horizontal Distance (HD)

Root = 0

Left Child:
HD - 1

Right Child:
HD + 1

--------------------------------

Example:

          1
        /   \
       2     3
      / \   / \
     4  5  6   7

HD values:

          1(0)
        /      \
     2(-1)    3(+1)
     /  \      / \
 4(-2) 5(0) 6(0) 7(+2)

--------------------------------

Vertical Lines:

HD = -2 → [4]

HD = -1 → [2]

HD =  0 → [1,5,6]

HD = +1 → [3]

HD = +2 → [7]

Answer:

[
 [4],
 [2],
 [1,5,6],
 [3],
 [7]
]

--------------------------------

🧠 Core Idea

Use BFS.

Store:

(node, horizontal distance)

For every node:

Put node value inside
map[hd].

--------------------------------

Why BFS?

Maintains top-to-bottom order
inside the same vertical line.

--------------------------------

Data Structure

map<int, vector<int>>

key   = HD

value = nodes in that column

Map automatically keeps
HD sorted.

--------------------------------

Algorithm

1. Root at HD = 0

2. Perform BFS

3. Left child:
   hd - 1

4. Right child:
   hd + 1

5. Store node in map[hd]

6. Traverse map
   from leftmost to rightmost

--------------------------------

⏱️ Time Complexity

O(N log N)

N insertions into map.

--------------------------------

🧠 Space Complexity

O(N)

Map + Queue

--------------------------------

🧩 Pattern

Tree BFS

Horizontal Distance

--------------------------------

🎯 Category

Binary Tree

Level Order Traversal

--------------------------------

🧠 Interview One-Liner

Assign every node a horizontal
distance from the root and use
BFS with a map to group nodes
column-wise from left to right.

*/

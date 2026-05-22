/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
public:

    int height(Node* root) {

        if(root == NULL) {
            return -1;
        }

        int leftHeight =
            1 + height(root->left);

        int rightHeight =
            1 + height(root->right);

        return max(leftHeight,
                   rightHeight);
    }

    int diameter(Node* root) {

        if(root == NULL) {
            return 0;
        }

        // Diameter passing through root
        int leftHeight =
            height(root->left);

        int rightHeight =
            height(root->right);

        int throughRoot =
            leftHeight + rightHeight + 2;

        // Diameter in left subtree
        int leftDiameter =
            diameter(root->left);

        // Diameter in right subtree
        int rightDiameter =
            diameter(root->right);

        return max({
            throughRoot,
            leftDiameter,
            rightDiameter
        });
    }
};

/*
==========================
🔥 DIAMETER OF BINARY TREE
==========================

Goal:

Find the longest path between
any two nodes in the tree.

--------------------------------

🧠 Diameter Meaning

Diameter =
Number of edges in the
longest path.

The path may or may not
pass through root.

--------------------------------

Core Observation:

For every node,

Possible diameter passing
through that node:

leftHeight +
rightHeight + 2

--------------------------------

Three Possibilities:

1. Diameter passes through root

   leftHeight + rightHeight + 2

2. Diameter lies completely
   in left subtree

3. Diameter lies completely
   in right subtree

Take maximum of all.

--------------------------------

Example:

         1
        / \
       2   3
      / \
     4   5

Longest path:

4 → 2 → 1 → 3

Edges = 3

Diameter = 3

--------------------------------

Recurrence:

diameter(root) =

max(
    leftHeight + rightHeight + 2,
    diameter(left),
    diameter(right)
)

--------------------------------

⏱️ Time Complexity

O(N²)

Why?

For every node,
height() traverses subtree again.

height() → O(N)

diameter() called for every node.

--------------------------------

🧠 Space Complexity

O(H)

Recursion stack

H = height of tree

Worst Case:
O(N)

Balanced Tree:
O(log N)

--------------------------------

🔥 Optimized Version

Compute height and diameter
in a single DFS.

Time Complexity:

O(N)

--------------------------------

🧩 Pattern

Tree DFS
Height + Diameter

--------------------------------

🎯 Category

Binary Tree

--------------------------------

🧠 Interview One-Liner

Diameter at a node equals
left subtree height +
right subtree height + 2,
and overall answer is the
maximum among all nodes.

*/

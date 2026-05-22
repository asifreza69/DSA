/*
Structure of a Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
public:

    // Check whether two trees
    // are exactly identical
    bool solve(Node *root1,
               Node *root2) {

        if(root1 == NULL &&
           root2 == NULL) {

            return true;
        }

        if(root1 == NULL ||
           root2 == NULL) {

            return false;
        }

        if(root1->data !=
           root2->data) {

            return false;
        }

        return
            solve(root1->left,
                  root2->left)
            &&
            solve(root1->right,
                  root2->right);
    }

    bool isSubTree(Node *root1,
                   Node *root2) {

        // Empty tree is subtree
        if(root2 == NULL) {
            return true;
        }

        // Main tree exhausted
        if(root1 == NULL) {
            return false;
        }

        // Check current node
        if(solve(root1, root2)) {
            return true;
        }

        // Search left or right
        return
            isSubTree(root1->left,
                      root2)
            ||
            isSubTree(root1->right,
                      root2);
    }
};

/*
==========================
🔥 SUBTREE OF ANOTHER TREE
==========================

Goal:

Check whether root2 exists as
a complete subtree inside root1.

--------------------------------

🧠 Core Idea

For every node in root1:

1. Assume it is the root of
   the subtree.

2. Check whether both trees
   are identical.

3. If not found,
   search left subtree.

4. Search right subtree.

--------------------------------

Two DFS Functions

1. solve()

Checks whether two trees
are completely identical.

2. isSubTree()

Traverses root1 and tries
every node as a possible
subtree root.

--------------------------------

Example

Main Tree:

          3
         / \
        4   5
       / \
      1   2

Subtree:

        4
       / \
      1   2

Answer = true

--------------------------------

Example

Main Tree:

          3
         / \
        4   5
       / \
      1   2
         /
        0

Subtree:

        4
       / \
      1   2

Answer = false

Structure differs.

--------------------------------

Algorithm

For each node:

if identical(root1, root2)
    return true

search left subtree

search right subtree

--------------------------------

⏱️ Time Complexity

Worst Case:

O(N × M)

N = nodes in root1
M = nodes in root2

Because for every node
of root1 we may compare
the entire root2 tree.

--------------------------------

🧠 Space Complexity

O(H1 + H2)

Recursive stack

H1 = height of root1
H2 = height of root2

Worst Case:
O(N)

--------------------------------

🧩 Pattern

Tree DFS
+
Tree Matching

--------------------------------

🎯 Category

Binary Tree

--------------------------------

🧠 Interview One-Liner

Traverse every node of the main
tree and check whether the subtree
rooted there is identical to the
given subtree.

*/

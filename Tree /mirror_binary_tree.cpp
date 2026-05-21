/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
public:

    void mirror(Node* root) {

        // Empty tree
        if(root == NULL) {
            return;
        }

        // Recursively mirror subtrees
        mirror(root->left);
        mirror(root->right);

        // Swap left and right child
        Node* temp = root->left;

        root->left = root->right;
        root->right = temp;
    }
};

/*
==========================
🔥 MIRROR / INVERT
BINARY TREE
==========================

Goal:
Convert the binary tree into
its mirror image.

--------------------------------

🧠 Core Idea:

For every node:
swap left child and right child.

Do this recursively for the
entire tree.

--------------------------------

Operation:

Before:

        1
       / \
      2   3

After:

        1
       / \
      3   2

--------------------------------

Recurrence:

mirror(root):

1. Mirror left subtree
2. Mirror right subtree
3. Swap left and right

--------------------------------

Base Case:

root == NULL
→ return

--------------------------------

Example:

Original:

        1
       / \
      2   3
     / \
    4   5

Mirrored:

        1
       / \
      3   2
         / \
        5   4

--------------------------------

⏱️ Time Complexity:
O(n)

Every node visited once.

--------------------------------

🧠 Space Complexity:
O(h)

h = height of tree
(recursion stack)

Worst case:
O(n)

Balanced tree:
O(log n)

--------------------------------

🧩 Pattern:
Tree DFS / Recursion

--------------------------------

🎯 Category:
Binary Tree

--------------------------------

🧠 Interview One-Liner:

Recursively swap left and right
child pointers of every node.

*/

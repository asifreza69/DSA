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

    // Find height of tree
    int height(Node* root) {

        if(root == NULL) {
            return 0;
        }

        int leftHeight =
            1 + height(root->left);

        int rightHeight =
            1 + height(root->right);

        return max(leftHeight,
                   rightHeight);
    }

    bool isBalanced(Node* root) {

        // Empty tree is balanced
        if(root == NULL) {
            return true;
        }

        // Height difference
        int leftHeight =
            height(root->left);

        int rightHeight =
            height(root->right);

        // Current node unbalanced
        if(abs(leftHeight -
               rightHeight) > 1) {

            return false;
        }

        // Check subtrees
        bool leftBalanced =
            isBalanced(root->left);

        bool rightBalanced =
            isBalanced(root->right);

        return leftBalanced &&
               rightBalanced;
    }
};

/*
==========================
🔥 BALANCED BINARY TREE
==========================

Goal:
Check whether the binary tree
is height balanced.

--------------------------------

🧠 Balanced Tree Condition:

For every node:

| leftHeight - rightHeight | ≤ 1

--------------------------------

🧠 Core Idea:

1. Compute height of left subtree
2. Compute height of right subtree
3. Check difference
4. Recursively check children

--------------------------------

Definition:

A tree is balanced if:

1. Current node balanced
2. Left subtree balanced
3. Right subtree balanced

--------------------------------

Example:

        1
       / \
      2   3
     /
    4

Balanced → true

--------------------------------

Unbalanced Example:

        1
       /
      2
     /
    3

Difference > 1

Answer = false

--------------------------------

⏱️ Time Complexity:
O(n²)

Why?

For every node,
height() traverses subtree again.

--------------------------------

🧠 Space Complexity:
O(h)

h = height of tree

--------------------------------

🔥 Optimized Approach:

Use single DFS returning height.

If subtree unbalanced:
return -1 immediately.

That gives:
Time = O(n)

--------------------------------

🧩 Pattern:
Tree DFS / Bottom-Up Height

--------------------------------

🎯 Category:
Binary Tree

--------------------------------

🧠 Interview One-Liner:

A binary tree is balanced if
height difference of left and
right subtree is at most 1 for
every node.

*/

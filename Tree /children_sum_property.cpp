class Solution {
public:

    bool isSumProperty(Node *root) {

        // Empty tree
        if(root == NULL){
            return true;
        }

        // Leaf node
        if(root->left == NULL &&
           root->right == NULL){
            return true;
        }

        int left = 0;
        int right = 0;

        if(root->left != NULL){
            left = root->left->data;
        }

        if(root->right != NULL){
            right = root->right->data;
        }

        // Current node check
        if(root->data != left + right){
            return false;
        }

        // Check left and right subtree
        return isSumProperty(root->left)
            && isSumProperty(root->right);
    }
};

/*
==========================
🔥 CHILDREN SUM PROPERTY
==========================

Goal:
Check whether every non-leaf node
satisfies:

node->data =
leftChild->data + rightChild->data

--------------------------------

🧠 Core Idea:

For each node:

1. Calculate left child value
2. Calculate right child value
3. Verify:

   root->data == left + right

4. Recursively check both subtrees

--------------------------------

Base Cases:

1. NULL node
   → true

2. Leaf node
   → true

Why?

Children Sum Property is only
checked for non-leaf nodes.

--------------------------------

Example:

        10
       /  \
      8    2

10 = 8 + 2

Answer = true

--------------------------------

Example:

        35
       /  \
      20   15
     / \
    15  5

35 = 20 + 15
20 = 15 + 5

Answer = true

--------------------------------

Example:

        10
       /  \
      3    4

10 ≠ 7

Answer = false

--------------------------------

⏱️ Time Complexity:
O(n)

Every node visited once.

--------------------------------

🧠 Space Complexity:
O(h)

h = height of tree

Recursive stack space.

Worst Case:
O(n)

Balanced Tree:
O(log n)

--------------------------------

🧩 Pattern:
Tree DFS
Property Verification

--------------------------------

🎯 Category:
Binary Tree

--------------------------------

🧠 Interview One-Liner:

Check whether every non-leaf node
equals the sum of its left and
right child values.

*/

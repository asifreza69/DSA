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

    int count = 0;

    bool solve(Node* root) {

        // Empty tree
        if(root == NULL) {
            return true;
        }

        bool left =
            solve(root->left);

        bool right =
            solve(root->right);

        // Left child value mismatch
        if(root->left != NULL &&
           root->left->data != root->data) {

            return false;
        }

        // Right child value mismatch
        if(root->right != NULL &&
           root->right->data != root->data) {

            return false;
        }

        // Child subtree not single valued
        if(!left || !right) {
            return false;
        }

        // Current subtree is single valued
        count++;

        return true;
    }

    int singlevalued(Node *root) {

        count = 0;

        solve(root);

        return count;
    }
};

/*
==========================
🔥 COUNT SINGLE VALUED
SUBTREES
==========================

Goal:

Count the number of subtrees
where all nodes have the
same value.

--------------------------------

🧠 Single Valued Subtree

A subtree is single valued if:

Every node inside that subtree
contains the same value.

--------------------------------

Examples

        5
       / \
      5   5

All nodes = 5

Whole tree is single valued.

Count = 3 leaf nodes
      + 1 root subtree

Total = 4

--------------------------------

Example

        5
       / \
      1   5

Leaf(1) → valid

Leaf(5) → valid

Root subtree → invalid

Count = 2

--------------------------------

🧠 Core Idea

Use Postorder Traversal.

Process:

1. Check left subtree
2. Check right subtree
3. Verify child values
4. Verify both subtrees are
   already single valued
5. Count current subtree

--------------------------------

Conditions for Current Node

Left subtree must be
single valued.

Right subtree must be
single valued.

If left child exists:

left->data == root->data

If right child exists:

right->data == root->data

--------------------------------

Why Postorder?

Because before deciding whether
current subtree is single valued,
we must know the status of both
children.

--------------------------------

Example

         5
        / \
       5   5
      /
     5

Step:

Leaf(5) → count++

Subtree(5,5) → count++

Right leaf → count++

Whole tree → count++

Answer = 4

--------------------------------

⏱️ Time Complexity

O(N)

Every node visited once.

--------------------------------

🧠 Space Complexity

O(H)

H = height of tree

Recursion stack space.

Worst Case:
O(N)

Balanced Tree:
O(log N)

--------------------------------

🧩 Pattern

Postorder DFS

Tree Property Checking

--------------------------------

🎯 Category

Binary Tree

--------------------------------

🧠 Interview One-Liner

Use postorder traversal and
return whether a subtree is
single valued; increment count
whenever both child subtrees and
child values satisfy the condition.

*/

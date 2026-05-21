/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
public:

    /*
    Check whether two subtrees
    are mirror images.
    */
    bool solve(Node* leftTree,
               Node* rightTree) {

        // Both NULL
        if(leftTree == NULL &&
           rightTree == NULL) {

            return true;
        }

        // One NULL
        if(leftTree == NULL ||
           rightTree == NULL) {

            return false;
        }

        // Values differ
        if(leftTree->data !=
           rightTree->data) {

            return false;
        }

        /*
        Mirror comparison:

        leftTree->left
        with
        rightTree->right

        AND

        leftTree->right
        with
        rightTree->left
        */
        return
            solve(leftTree->left,
                  rightTree->right)
            &&
            solve(leftTree->right,
                  rightTree->left);
    }

    bool isSymmetric(Node* root) {

        // Empty tree
        if(root == NULL) {
            return true;
        }

        // Compare left and right subtree
        return solve(root->left,
                     root->right);
    }
};

/*
==========================
🔥 SYMMETRIC BINARY TREE
==========================

Goal:
Check whether the binary tree
is symmetric around its center.

--------------------------------

🧠 Core Idea:

A tree is symmetric if:

Left subtree is a mirror image
of right subtree.

--------------------------------

Mirror Conditions:

1. Values must match
2. left->left matches right->right
3. left->right matches right->left

--------------------------------

Recurrence:

mirror(l, r) =

(l->data == r->data)

AND

mirror(l->left, r->right)

AND

mirror(l->right, r->left)

--------------------------------

Base Cases:

Both NULL
→ true

One NULL
→ false

--------------------------------

Example:

        1
      /   \
     2     2
    / \   / \
   3  4  4  3

Answer = true

--------------------------------

Not Symmetric:

        1
      /   \
     2     2
      \     \
       3     3

Answer = false

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

Balanced:
O(log n)

--------------------------------

🧩 Pattern:
Tree DFS / Mirror Recursion

--------------------------------

🎯 Category:
Binary Tree

--------------------------------

🧠 Interview One-Liner:

A tree is symmetric if its left
and right subtree are mirror
images of each other.

*/

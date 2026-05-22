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

    int inOrderSuccessor(Node *root,
                         Node *k) {

        int successor = -1;

        while(root != NULL) {

            /*
            Current node can be
            a possible successor
            */
            if(k->data < root->data) {

                successor = root->data;

                root = root->left;
            }
            else {

                root = root->right;
            }
        }

        return successor;
    }
};

/*
==========================
🔥 INORDER SUCCESSOR IN BST
==========================

Goal:

Find the inorder successor of
a given node in a BST.

--------------------------------

🧠 What is Inorder Successor?

The next greater element in
the inorder traversal.

--------------------------------

Example:

BST:

         20
        /  \
      10    30
           /
         25

Inorder:

10 20 25 30

Successor of 20 = 25

--------------------------------

🧠 Core Idea

Whenever:

k->data < root->data

Current root can be the
successor because it is
greater than k.

Store it and move LEFT
to search for a smaller
valid successor.

--------------------------------

Otherwise:

k->data >= root->data

Successor cannot be in
left subtree.

Move RIGHT.

--------------------------------

Visualization:

         20
        /  \
      10    30
           /
         25

k = 20

20 < 20 ? No
Move right

root = 30

20 < 30 ? Yes

successor = 30

Move left

root = 25

20 < 25 ? Yes

successor = 25

Move left

NULL

Answer = 25

--------------------------------

Why BST Property Works?

Left Subtree:
smaller values

Right Subtree:
greater values

We use this ordering to
avoid full traversal.

--------------------------------

⏱️ Time Complexity

Balanced BST:
O(log N)

Worst Case (Skew Tree):
O(N)

--------------------------------

🧠 Space Complexity

O(1)

No recursion
No extra data structure

--------------------------------

🧩 Pattern

BST Search

Lower Bound Concept

--------------------------------

🎯 Category

Binary Search Tree (BST)

--------------------------------

🧠 Interview One-Liner

Keep moving through the BST;
whenever a node is greater than
the target, store it as a
possible successor and move left
to find a smaller valid answer.

*/

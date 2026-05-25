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

    Node* lca(Node* root,
              int n1,
              int n2) {

        if(root == NULL) {
            return NULL;
        }

        if(root->data == n1 ||
           root->data == n2) {

            return root;
        }

        Node* leftans =
        lca(root->left, n1, n2);

        Node* rightans =
        lca(root->right, n1, n2);

        if(leftans != NULL &&
           rightans != NULL) {

            return root;
        }

        if(leftans == NULL) {
            return rightans;
        }

        return leftans;
    }
};

/*
=================================================
LOWEST COMMON ANCESTOR (LCA)
IN A BINARY TREE
=================================================

Problem:

Find the lowest (deepest) node
that has both n1 and n2 in its
subtree.

A node can be its own ancestor.

-------------------------------------------------

Example:

            1
          /   \
         2     3
        / \   / \
       4   5 6   7

LCA(4,5) = 2

LCA(4,6) = 1

LCA(3,7) = 3

-------------------------------------------------

Core Idea

For every node:

Ask left subtree:

"Do you contain n1 or n2?"

Ask right subtree:

"Do you contain n1 or n2?"

-------------------------------------------------

Case 1

Both sides return non-null.

        Root
       /    \
      ✓      ✓

One target found in left subtree.

Other target found in right subtree.

Current node becomes LCA.

-------------------------------------------------

Case 2

Only left returns non-null.

Return left answer upward.

-------------------------------------------------

Case 3

Only right returns non-null.

Return right answer upward.

-------------------------------------------------

Case 4

Current node itself equals
n1 or n2.

Return current node.

-------------------------------------------------

Dry Run

            1
          /   \
         2     3
        / \
       4   5

Find LCA(4,5)

Node 4 returns itself.

Node 5 returns itself.

At node 2:

left = 4

right = 5

Both non-null

Return 2

Answer = 2

-------------------------------------------------

Why It Works

The first node from the bottom
that receives one target from
each side must be the lowest
common ancestor.

-------------------------------------------------

Complexity

Time:

O(N)

Every node visited once.

-------------------------------------------------

Space:

O(H)

Recursion stack.

H = Tree Height

Balanced Tree:
O(log N)

Skewed Tree:
O(N)

-------------------------------------------------

Pattern

Binary Tree

Postorder DFS

Lowest Common Ancestor

-------------------------------------------------

Interview One-Liner

Recursively search both subtrees;
if one target is found on each side,
the current node is the LCA.

=================================================
*/

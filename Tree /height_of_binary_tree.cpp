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

        // Empty tree
        if(root == NULL) {
            return -1;
        }

        // Height of left subtree
        int leftHeight =
            1 + height(root->left);

        // Height of right subtree
        int rightHeight =
            1 + height(root->right);

        // Maximum height
        return max(leftHeight,
                   rightHeight);
    }
};

/*
==========================
🔥 HEIGHT OF BINARY TREE
==========================

Goal:
Find the height (maximum depth)
of a binary tree.

--------------------------------

🧠 Core Idea:

Height of a node =
1 + maximum height of its
left and right subtree.

--------------------------------

Recurrence:

height(root) =
1 + max(
        height(left),
        height(right)
    )

--------------------------------

Base Case:

root == NULL
→ return -1

Why -1?

Because:
Leaf node height becomes:

1 + max(-1, -1) = 0

So:
Leaf height = 0

(This definition counts edges.)

--------------------------------

Alternative Convention:

If NULL returns 0,
then leaf height becomes 1.

That version counts nodes.

--------------------------------

Example:

        1
       / \
      2   3
     /
    4

Height = 2

Longest path:
1 → 2 → 4

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
Tree DFS

--------------------------------

🎯 Category:
Binary Tree

--------------------------------

🧠 Interview One-Liner:

Height of a tree is
1 + max(leftHeight, rightHeight).

*/

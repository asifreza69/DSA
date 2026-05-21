/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
public:

    bool isIdentical(Node* r1,
                     Node* r2) {

        // Both NULL
        if(r1 == NULL &&
           r2 == NULL) {

            return true;
        }

        // One NULL, one not NULL
        if(r1 == NULL ||
           r2 == NULL) {

            return false;
        }

        // Data mismatch
        if(r1->data != r2->data) {
            return false;
        }

        // Check left and right subtree
        return
            isIdentical(r1->left,
                        r2->left)
            &&
            isIdentical(r1->right,
                        r2->right);
    }
};

/*
==========================
🔥 IDENTICAL BINARY TREES
==========================

Goal:
Check whether two binary trees
are exactly identical.

Two trees are identical if:

1. Structure is same
2. Node values are same

--------------------------------

🧠 Core Idea:

Compare nodes recursively.

For every pair of nodes:

1. Values must match
2. Left subtree must match
3. Right subtree must match

--------------------------------

Conditions:

Both NULL
→ true

One NULL
→ false

Values differ
→ false

Otherwise:
check left and right recursively

--------------------------------

Recurrence:

isIdentical(r1, r2) =
(
    r1->data == r2->data
)
&&
isIdentical(left1, left2)
&&
isIdentical(right1, right2)

--------------------------------

Example:

Tree 1:          Tree 2:

    1                1
   / \              / \
  2   3            2   3

Answer = true

--------------------------------

Example 2:

    1                1
   /                  \
  2                    2

Answer = false

Structure differs.

--------------------------------

⏱️ Time Complexity:
O(n)

Visit each node once.

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
Tree DFS / Recursion

--------------------------------

🎯 Category:
Binary Tree

--------------------------------

🧠 Interview One-Liner:

Two trees are identical if
their root values, left subtree,
and right subtree all match.

*/

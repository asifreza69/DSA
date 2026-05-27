/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *
 *     TreeNode() : val(0),
 *                  left(nullptr),
 *                  right(nullptr) {}
 *
 *     TreeNode(int x) : val(x),
 *                       left(nullptr),
 *                       right(nullptr) {}
 *
 *     TreeNode(int x,
 *              TreeNode *left,
 *              TreeNode *right)
 *              : val(x),
 *                left(left),
 *                right(right) {}
 * };
 */

class Solution {
public:

    TreeNode* solve(TreeNode* root,
                    int target) {

        if(root == NULL) {
            return NULL;
        }

        // Process children first
        root->left =
        solve(root->left, target);

        root->right =
        solve(root->right, target);

        // Delete current node
        // if it becomes a leaf
        // and value == target

        if(root->left == NULL &&
           root->right == NULL &&
           root->val == target) {

            return NULL;
        }

        return root;
    }

    TreeNode* removeLeafNodes(
        TreeNode* root,
        int target
    ) {

        return solve(root, target);
    }
};

/*
=================================================
DELETE LEAVES WITH A GIVEN VALUE
=================================================

Problem:

Delete every leaf node whose
value equals target.

Important:

After deleting leaves,
some parent nodes may
become new leaves.

Those should also be deleted
if their value == target.

-------------------------------------------------

Example:

Target = 2

            1
           / \
          2   3
         /   / \
        2   2   4

Step 1:
Delete leaf 2 nodes

            1
           / \
          2   3
               \
                4

Now left node 2 becomes leaf.

Step 2:
Delete it too

            1
             \
              3
               \
                4

-------------------------------------------------

Core Idea

Process children BEFORE parent.

This is a classic:

Postorder DFS

because parent decision depends
on updated children.

-------------------------------------------------

Traversal Order

Left subtree

Right subtree

Current node

-------------------------------------------------

Why Postorder?

Suppose:

        2
       /
      2

If top node is checked first,
it is NOT a leaf yet.

After deleting child,
top node becomes leaf.

So children must be processed
before parent.

-------------------------------------------------

Key Condition

Delete node if:

left == NULL
AND
right == NULL
AND
node value == target

-------------------------------------------------

Dry Run

        2
       /
      2

Recursive calls:

Delete child 2

Parent becomes leaf

Delete parent 2

Final Tree:

NULL

-------------------------------------------------

Complexity

Time:
O(N)

Every node visited once.

-------------------------------------------------

Space:
O(H)

Recursive stack.

H = Tree height

Worst Case:
O(N)

Balanced Tree:
O(log N)

-------------------------------------------------

Pattern

Binary Tree

Postorder DFS

Tree Modification

-------------------------------------------------

Interview One-Liner

Use postorder traversal so that
children are processed first;
after updating subtrees, delete
the current node if it becomes
a target-valued leaf.

=================================================
*/

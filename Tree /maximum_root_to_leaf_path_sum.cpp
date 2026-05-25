/* structure of a binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
public:

    void solve(Node* root,
               int &ans) {

        if(root == NULL) {
            return;
        }

        // Leaf node
        if(root->left == NULL &&
           root->right == NULL) {

            ans = max(ans,
                      root->data);
        }

        // Pass path sum to children

        if(root->left != NULL) {
            root->left->data +=
            root->data;
        }

        if(root->right != NULL) {
            root->right->data +=
            root->data;
        }

        solve(root->left, ans);
        solve(root->right, ans);
    }

    int maxPathSum(Node* root) {

        if(root == NULL) {
            return 0;
        }

        int ans = INT_MIN;

        solve(root, ans);

        return ans;
    }
};

/*
=================================================
MAXIMUM ROOT TO LEAF PATH SUM
=================================================

Problem:

Find the maximum sum among all
root-to-leaf paths.

-------------------------------------------------

Example:

          10
         /  \
        2    10
            /  \
          20    1

Root → Leaf sums:

10 + 2      = 12

10 + 10 +20 = 40

10 + 10 +1  = 21

Answer = 40

-------------------------------------------------

Core Idea:

Carry the running path sum
from parent to child.

For every node:

child_sum =
parent_sum + child_value

When a leaf node is reached:

update answer.

-------------------------------------------------

What This Code Does

Instead of maintaining a
separate sum variable,

it stores cumulative sum
directly inside child nodes.

Example:

      10
     /
    2

becomes

      10
     /
    12

-------------------------------------------------

Leaf Node Check

if(left == NULL &&
   right == NULL)

This means a complete
root-to-leaf path has ended.

Update maximum answer.

-------------------------------------------------

Traversal Type

DFS

Preorder Traversal

Parent processed before
children.

-------------------------------------------------

Dry Run

          5
         / \
        4   8
           / \
          6   3

After propagation:

          5
         / \
        9   13
           /  \
         19   16

Leaf values:

9, 19, 16

Maximum = 19

-------------------------------------------------

Complexity

Time:
O(N)

Every node visited once.

-------------------------------------------------

Space:

O(H)

Recursion stack.

H = Height of tree.

Worst Case:
O(N)

Balanced Tree:
O(log N)

-------------------------------------------------

Note

This solution modifies the
original tree values.

Interviewers usually prefer:

solve(node, currentSum)

without changing node data.

-------------------------------------------------

Better Version

solve(root, sum)

sum += root->data

Pass sum to children.

Update answer at leaf.

-------------------------------------------------

Pattern

Tree DFS

Root-to-Leaf Path Problems

-------------------------------------------------

Interview One-Liner

Propagate cumulative path sums
from parent to child and update
the maximum whenever a leaf node
is reached.

=================================================
*/

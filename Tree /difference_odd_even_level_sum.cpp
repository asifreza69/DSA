/* The Node structure is
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
public:

    int getLevelDiff(Node *root) {

        if(root == NULL) {
            return 0;
        }

        queue<Node*> q;

        q.push(root);

        int ans = 0;

        int level = 0;

        while(!q.empty()) {

            int size = q.size();

            while(size--) {

                Node* node = q.front();
                q.pop();

                if(level % 2 == 0) {
                    ans += node->data;
                }
                else {
                    ans -= node->data;
                }

                if(node->left) {
                    q.push(node->left);
                }

                if(node->right) {
                    q.push(node->right);
                }
            }

            level++;
        }

        return ans;
    }
};

/*
=================================================
DIFFERENCE BETWEEN ODD AND EVEN LEVEL SUMS
=================================================

Problem:

Find:

(sum of nodes at odd levels)
-
(sum of nodes at even levels)

Root is considered at
Level 1 (Odd Level).

-------------------------------------------------

Example:

          1
        /   \
       2     3
      / \   / \
     4  5  6   7

Odd Levels:

Level 1 = 1

Level 3 = 4 + 5 + 6 + 7 = 22

Odd Sum = 23

Even Levels:

Level 2 = 2 + 3 = 5

Even Sum = 5

Answer:

23 - 5 = 18

-------------------------------------------------

Core Idea

Perform Level Order Traversal
(BFS).

For every level:

Odd level  -> Add node values

Even level -> Subtract node values

Final answer automatically becomes:

Odd Sum - Even Sum

-------------------------------------------------

How Level Is Managed

level = 0

Level 0 -> Tree Level 1 (Odd)

Level 1 -> Tree Level 2 (Even)

Level 2 -> Tree Level 3 (Odd)

Hence:

level % 2 == 0
=> Add

level % 2 == 1
=> Subtract

-------------------------------------------------

Dry Run

        10
       /  \
      20  30

Level 0:

ans = 10

Level 1:

ans = 10 - 20 - 30

ans = -40

Answer = -40

Which equals:

10 - (20 + 30)

-------------------------------------------------

Complexity

Time Complexity:

O(N)

Every node visited once.

-------------------------------------------------

Space Complexity:

O(N)

Queue stores nodes of a level.

-------------------------------------------------

Pattern

Binary Tree

Level Order Traversal (BFS)

Level Based Processing

-------------------------------------------------

Interview One-Liner

Use BFS level-order traversal and
add nodes at odd levels while
subtracting nodes at even levels
to directly compute the required
difference.

=================================================
*/

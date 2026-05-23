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

    // Left Boundary
    void leftans(Node* root,
                 vector<int>& temp) {

        if(root == NULL) {
            return;
        }

        // Skip leaf nodes
        if(root->left == NULL &&
           root->right == NULL) {
            return;
        }

        temp.push_back(root->data);

        if(root->left != NULL) {
            leftans(root->left, temp);
        }
        else {
            leftans(root->right, temp);
        }
    }

    // Leaf Nodes
    void leafans(Node* root,
                 vector<int>& temp) {

        if(root == NULL) {
            return;
        }

        if(root->left == NULL &&
           root->right == NULL) {

            temp.push_back(root->data);
            return;
        }

        leafans(root->left, temp);
        leafans(root->right, temp);
    }

    // Right Boundary
    void rightans(Node* root,
                  vector<int>& temp) {

        if(root == NULL) {
            return;
        }

        // Skip leaf nodes
        if(root->left == NULL &&
           root->right == NULL) {
            return;
        }

        if(root->right != NULL) {
            rightans(root->right, temp);
        }
        else {
            rightans(root->left, temp);
        }

        // Add during backtracking
        temp.push_back(root->data);
    }

    vector<int> boundaryTraversal(Node *root) {

        if(root == NULL) {
            return {};
        }

        // Single node tree
        if(root->left == NULL &&
           root->right == NULL) {

            return {root->data};
        }

        vector<int> ans;
        vector<int> temp;

        // Root
        ans.push_back(root->data);

        // Left Boundary
        leftans(root->left, temp);

        for(auto x : temp) {
            ans.push_back(x);
        }

        temp.clear();

        // Leaf Nodes
        leafans(root->left, temp);
        leafans(root->right, temp);

        for(auto x : temp) {
            ans.push_back(x);
        }

        temp.clear();

        // Right Boundary (bottom-up)
        rightans(root->right, temp);

        for(auto x : temp) {
            ans.push_back(x);
        }

        return ans;
    }
};

/*
==========================
🔥 BOUNDARY TRAVERSAL
OF BINARY TREE
==========================

Goal:

Print boundary nodes in
Anti-Clockwise order.

--------------------------------

Boundary Traversal consists of:

1. Root
2. Left Boundary
3. Leaf Nodes
4. Right Boundary (Reverse)

--------------------------------

Traversal Order:

          Root
            ↓
    Left Boundary
            ↓
       Leaf Nodes
            ↓
 Reverse Right Boundary

--------------------------------

Example:

             1
           /   \
          2     3
         / \   / \
        4   5 6   7

Boundary:

1 2 4 5 6 7 3

--------------------------------

🧠 Core Idea

Break problem into 3 parts:

1. Left Boundary
2. Leaves
3. Right Boundary

Then combine them.

--------------------------------

Left Boundary Rules

Take nodes while moving:

Prefer Left

Else Right

Do NOT include leaves.

--------------------------------

Leaf Traversal

Simple DFS.

Take only nodes where:

left == NULL
and
right == NULL

--------------------------------

Right Boundary Rules

Prefer Right

Else Left

Do NOT include leaves.

Store during backtracking
to get reverse order.

--------------------------------

Why skip leaves?

Otherwise leaf nodes would
appear twice:

Once in boundary

Once in leaf traversal

--------------------------------

Example

             20
           /    \
         8       22
       /   \       \
      4    12       25
          /  \
        10   14

Boundary:

20
8
4 10 14 25
22

Answer:

20 8 4 10 14 25 22

--------------------------------

⏱️ Time Complexity

O(N)

Each node visited at most once.

--------------------------------

🧠 Space Complexity

O(H)

Recursive stack

H = height of tree

Worst Case:
O(N)

Balanced Tree:
O(log N)

--------------------------------

🧩 Pattern

Tree DFS

Boundary Traversal

--------------------------------

🎯 Category

Binary Tree

--------------------------------

🧠 Interview One-Liner

Boundary traversal is obtained by
combining left boundary, all leaf
nodes, and reverse right boundary
while avoiding duplicate leaf nodes.

*/

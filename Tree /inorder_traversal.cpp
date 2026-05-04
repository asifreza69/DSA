#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 * };
 */

class Solution {
public:
    void solve(vector<int>& ans, TreeNode* root){
        if(root == NULL){
            return;
        }

        // Left
        solve(ans, root->left);

        // Root
        ans.push_back(root->val);

        // Right
        solve(ans, root->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(ans, root);
        return ans;
    }
};

/*
==========================
🔥 APPROACH EXPLAINED
==========================

Inorder Traversal Order:
Left → Root → Right

--------------------------------

🧠 Idea:

- Traverse left subtree
- Visit current node
- Traverse right subtree

--------------------------------

Example:

        1
         \
          2
         /
        3

Inorder:
3 → 2 → 1

--------------------------------

Time Complexity: O(n)
Space Complexity: O(h)  (recursion stack)

--------------------------------

🧠 Interview One-Liner:

"Use DFS recursion with Left → Root → Right order"
*/

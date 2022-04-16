/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum = 0;

    void convertBSTUtil(TreeNode *root) {
        if (root == nullptr)
            return;
        convertBSTUtil(root->right);
        sum = sum + root->val;
        root->val = sum;
        convertBSTUtil(root->left);
    }

    TreeNode *convertBST(TreeNode *root) {
        convertBSTUtil(root);
        return root;
    }
};
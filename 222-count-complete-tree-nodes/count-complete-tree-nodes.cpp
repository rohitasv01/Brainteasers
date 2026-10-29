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
    int leftHeight(TreeNode* node)
    {
        if (!node)  return 0;
        return 1+leftHeight(node->left);
    }
    int rightHeight(TreeNode* node)
    {
        if(!node)   return 0;
        return 1+rightHeight(node->right);
    }
    int countNodes(TreeNode* root) {
        if(!root)   return 0;
        int lh=leftHeight(root->left);
        int rh=rightHeight(root->right);
        if(lh==rh)  return pow(2,lh+1)-1;
        else    return 1+countNodes(root->left)+countNodes(root->right);
    }
};
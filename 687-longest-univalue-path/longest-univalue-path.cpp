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
    int maxi=0;
    int solve(TreeNode* node)
    {
        if(!node)   return 0;
        int leftContri=solve(node->left);
        int rightContri=solve(node->right);
        if(node->left && node->val!=node->left->val)    leftContri=0;
        if(node->right && node->val!=node->right->val)  rightContri=0;
        maxi=max(maxi, leftContri+rightContri);
        return 1+max(leftContri, rightContri);
    }
    int longestUnivaluePath(TreeNode* root) {
        solve(root);
        return maxi;
    }
};
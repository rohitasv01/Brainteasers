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
    int ans=INT_MAX;
    int prev=-1;
    void solve(TreeNode* node)
    {
        if(!node)   return;
        solve(node->left);
        if(prev!=-1)    ans=min(ans, node->val-prev);
        prev=node->val;
        solve(node->right);
    }
    int getMinimumDifference(TreeNode* root) {
        solve(root);
        return ans;
    }
};
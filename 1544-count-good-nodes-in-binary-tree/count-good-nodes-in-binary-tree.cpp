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
    int ans=0;
    void solve(TreeNode* node, int maxi)
    {
        if(!node)   return;
        if(node->val>=maxi)  ans++;
        maxi=max(maxi, node->val);
        solve(node->left, maxi);
        solve(node->right,maxi);
    }
    int goodNodes(TreeNode* root) {
        solve(root, root->val);
        return ans;
    }
};
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
    long long  prev=LLONG_MIN;
    bool ans=true;
    void solve(TreeNode* node)
    {
        if(!node)   return;
        solve(node->left);
        if(prev!=LLONG_MIN)
        {
            if(prev>=node->val)   ans=false;
        }
        prev=(long long)node->val;
        solve(node->right);
    }
    bool isValidBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};
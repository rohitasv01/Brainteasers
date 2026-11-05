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
    void solve(TreeNode* node, int depth, string direction)
    {
        if(!node)   return ;
        ans=max(ans,depth);
        if(direction=="left")
        {
            solve(node->left, 1,"left");
            solve(node->right,depth+1,"right");
        }
        else
        {
            solve(node->left,depth+1,"left");
            solve(node->right, 1,"right");
        }
    }
    int longestZigZag(TreeNode* root) {
        solve(root->left, 1, "left");
        solve(root->right,1,"right");
        return ans;
    }
};
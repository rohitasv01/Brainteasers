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
    vector<vector<int>> ans;
    void solve(TreeNode* node, int sum, vector<int> & path, int targetSum)
    {
        if(!node)   return ;
        sum+=node->val;
        path.push_back(node->val);
        if(!node->left && !node->right && sum==targetSum)   ans.push_back(path);
        solve(node->left, sum,path,targetSum);
        solve(node->right, sum,path,targetSum);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        solve(root,0, path,targetSum);
        return ans;
    }
};
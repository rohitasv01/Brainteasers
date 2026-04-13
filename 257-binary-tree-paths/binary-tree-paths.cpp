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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path="";
        dfs(root,path,ans);
        return ans;
    }
    void dfs(TreeNode* node,string &path,vector<string> & ans)
    {
        if(node==NULL)  return;
        int len=path.size();
        if(path.size()!=0)  path+="->";
        path+=to_string(node->val);
        if(!node->left && !node->right) 
        {
            ans.push_back(path);
            path.resize(len);
            return ;
        }
        dfs(node->left,path,ans);
        dfs(node->right,path,ans);
        path.resize(len);
    }
};
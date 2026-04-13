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
        traverse(root,"",ans);
        return ans;
    }
    void traverse(TreeNode* node,string path,vector<string> &ans)
    {
        if(node==NULL)  return ;
        if(path!="") path+="->";
        path+=to_string(node->val);
        if(!node->left && !node->right)
        {
            ans.push_back(path);
            return ;
        } 
        traverse(node->left,path,ans);
        traverse(node->right,path ,ans);
    }
};
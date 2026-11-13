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
    int ans=-1;
    int count=0;
    void inorderTraversal(TreeNode* node, int k)
    {
        if(!node)   return ;
        inorderTraversal(node->left,k);
        count++;
        if(count==k)   ans=node->val;
        inorderTraversal(node->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorderTraversal(root,k);
        return ans;
    }
};
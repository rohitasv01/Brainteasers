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
    int sumNumbers(TreeNode* root) {
        return traverse(root,0);
    }
    int traverse(TreeNode* node,int num)
    {
        if(node==NULL)  return 0;
        num*=10;
        num+=node->val;
        if(!node->left && !node->right)     return num;
        return traverse(node->left,num) + traverse(node->right,num);
    }
};
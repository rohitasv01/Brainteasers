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
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        return hasSum(root,sum,targetSum);
    }
    bool hasSum(TreeNode* node,int sum,int targetSum)
    {
        if(node==NULL) return false;
        sum+=node->val;
        if(node->left==NULL && node->right==NULL && sum==targetSum) return true;
        return hasSum(node->left,sum,targetSum) || hasSum(node->right,sum,targetSum);
    }
};
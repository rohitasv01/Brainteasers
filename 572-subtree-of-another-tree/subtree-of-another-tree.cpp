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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL)  return false;
        if(isSameTree(root,subRoot))    return true;
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
 
    bool isSameTree(TreeNode* p1,TreeNode* p2)
    {
        if(p1==NULL || p2==NULL)
        {
            if(p1==p2)  return true;
            else return false;
        }
        return (p1->val==p2->val) && isSameTree(p1->right,p2->right) && isSameTree(p1->left,p2->left);
    }
};
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
    int height(TreeNode* node)
    {
        if(node==NULL)  return 0;
        int leftH=height(node->left);
        if(leftH==-1)  return -1;
        int rightH=height(node->right);
        if(rightH==-1) return -1;
        if(abs(rightH-leftH)>1) return -1;
        return 1 +max(leftH,rightH);
    }
    bool isBalanced(TreeNode* root) {
        if(height(root)==-1)    return false;
        else return true;
    }
};
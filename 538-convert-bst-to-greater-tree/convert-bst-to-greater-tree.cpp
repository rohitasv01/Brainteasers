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
    int traverse(TreeNode *node,int &carry)
    {
        if(node==NULL)  return 0;
        traverse(node->right,carry);
        node->val=node->val+carry;
        carry=node->val;
        traverse(node->left,carry);
        return carry;
    }
    TreeNode* convertBST(TreeNode* root) {
        int carry=0;
        traverse(root,carry);
        return root;
    }
};
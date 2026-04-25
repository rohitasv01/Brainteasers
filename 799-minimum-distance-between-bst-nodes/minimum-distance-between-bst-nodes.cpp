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
    int minDiff=INT_MAX;
    bool first=true;
    void traverse(TreeNode* node,int &prev)
    {
        if(node==NULL)  return ;
        traverse(node->left,prev);
        if(first==false)  minDiff=min(minDiff,node->val-prev);
        prev=node->val;
        first=false;
        traverse(node->right,prev);
    }
    int minDiffInBST(TreeNode* root) {
        int prev=-1;
        traverse(root,prev);
        return minDiff; 
    }
};
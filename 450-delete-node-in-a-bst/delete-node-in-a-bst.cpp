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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* curr=root;
        TreeNode* parent=NULL;
        while(curr && curr->val!=key)
        {
            parent =curr;
            curr=(curr->val>key) ?curr->left : curr->right;
        }
        if(curr==NULL)  return root;
        if(curr->left && curr->right)
        {
            TreeNode* succ=curr->right;
            TreeNode* succP=curr;
            while(succ->left)
            {
                succP=succ;
                succ=succ->left;
            }
            curr->val=succ->val;
            curr=succ;
            parent=succP;
        }
        TreeNode* child;
        if(curr->left)  child=curr->left;
        else child=curr->right;
        if(parent==NULL)    return child;
        if(parent->left==curr) 
        {
            parent ->left=child;
            delete curr;
        }
        else
        {
            parent->right=child;
            delete curr;
        }
        return root;
    }

};
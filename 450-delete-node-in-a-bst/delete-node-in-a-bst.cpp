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
        TreeNode* parent=NULL;
        TreeNode* curr=root;
        while(curr && curr->val!=key)
        {
            parent=curr;
            if(curr->val>key)   curr=curr->left;
            else curr=curr->right;
        }
        if(curr==NULL) return root;
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
            parent=succP;
            curr=succ;
        }
        TreeNode* child;
        if(curr->left)   child=curr->left;
        else child=curr->right;
        if(parent==NULL)    return child;
        if(parent->left==curr)  parent->left=child;
        else    parent->right=child;
        delete curr ;
        return root;
    }
};
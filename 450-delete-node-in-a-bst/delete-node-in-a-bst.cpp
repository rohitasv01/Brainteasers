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
    TreeNode* findSucc(TreeNode* node)
    {
        TreeNode* succ=node->right;
        while(succ->left)
        {
            succ=succ->left;
        }
        return succ;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)   return root;
        if(root->val==key)
        {
            if(!root->left)
            {
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }  
            else if(!root->right)
            {
                TreeNode* temp=root->left;
                delete root;
                return temp;
            } 
            else 
            {
                TreeNode* succ=findSucc(root);
                root->val=succ->val;
                root->right=deleteNode(root->right,succ->val);
            }
        }
        else if(root->val>key)  root->left=deleteNode(root->left, key);
        else root->right=deleteNode(root->right, key);
        return root;
    }
};
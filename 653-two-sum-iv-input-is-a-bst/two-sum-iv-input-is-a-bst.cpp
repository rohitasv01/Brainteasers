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
 class BSTIterator
 {
    stack<TreeNode*> st;
    bool reverse;
    public:
    BSTIterator(TreeNode* node, bool isReverse)
    {
        reverse=isReverse;
        pushAll(node);
    }
    int next()
    {
        TreeNode* temp=st.top();
        st.pop();
        if(!reverse)
        {
            if(temp->right) pushAll(temp->right);
        }
        else
        {
            if(temp->left)  pushAll(temp->left);
        }
        return temp->val;
    }
    void pushAll(TreeNode* node)
    {
        if(!reverse)
        {
            while(node)
            {
               st.push(node); 
               node=node->left;
            }
        }
        else
        {
            while(node)
            {
                st.push(node);
                node=node->right;
            }
        }
    }
 };
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)  return false;
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        int i=l.next();
        int j=r.next();
        while(i<j)
        {
            if(i+j==k)  return true;
            else if(i+j<k)  i=l.next();
            else    j=r.next();
        }
        return false;
    }
};
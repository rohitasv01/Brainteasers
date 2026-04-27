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
    void pushAll(TreeNode* node,stack<TreeNode*>&st)
    {
        while(node)
        {
            st.push(node);
            node=node->left;
        }
    }
    void taken(stack<TreeNode*>&st)
    {
        TreeNode* temp=st.top();
        st.pop();
        if(temp->right) pushAll(temp->right,st);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>ans;
        stack<TreeNode*>st1;
        stack<TreeNode*>st2;
        pushAll(root1,st1);
        pushAll(root2,st2);
        while(st1.size()!=0 && st2.size()!=0)
        {
        if(st1.top()->val<st2.top()->val)
        {
            ans.push_back(st1.top()->val);
            taken(st1);
        }
        else
        {
            ans.push_back(st2.top()->val);
            taken(st2);
        }
        }
        while(st1.size()!=0)
        {
            ans.push_back(st1.top()->val);
            taken(st1);
        }
        while(st2.size()!=0)
        {
            ans.push_back(st2.top()->val);
            taken(st2);
        }
        return ans;
    }
};
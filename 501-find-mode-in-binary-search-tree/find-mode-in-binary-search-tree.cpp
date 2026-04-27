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
    int maxCount=1;
    int count;
    vector<int> ans;
    void traverse(TreeNode* node,int &prev,int &count)
    {
        if(node==NULL)  return ;
        traverse(node->left,prev,count);
        if(prev==INT_MIN)   ans.push_back(node->val);
        else
        {
        if(node->val==prev)
        {
            count++;
            if(count==maxCount) ans.push_back(node->val);
            else if(count>maxCount) 
            {
                ans.erase(ans.begin(),ans.end());
                ans.push_back(node->val);
                maxCount=count;
            }
        }
        else   
        {
            count=1;
            if(count==maxCount) ans.push_back(node->val);
        } 
        }
        prev=node->val;
        traverse(node->right,prev,count);
    }
    vector<int> findMode(TreeNode* root) {
        int prev=INT_MIN,count=1;
        traverse(root,prev,count);
        return ans;
    }
};
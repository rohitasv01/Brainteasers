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
    int widthOfBinaryTree(TreeNode* root) {
        long long ans=0;
        if(root==NULL)  return 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(q.size()!=0)
        {
            int size=q.size();
            long long first=q.front().second;
            long long last;
            for(int i=0;i<size;i++)
            {
                auto[node,index]=q.front();
                q.pop();
                long long curr=index-first;
                if(i==size-1)   last=curr;
                if(node->left)  q.push({node->left,2*curr+1});
                if(node->right) q.push({node->right,2*curr+2});
            }
            ans=max(ans,last+1);
        }
        return ans;
    }

};
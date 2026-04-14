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
    TreeNode* markParent(TreeNode* root,unordered_map<TreeNode* ,TreeNode*> &parent,int start)
    {
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* target;
        while(q.size()!=0)
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(node->val==start)    target=node;
                if(node->left)
                {
                    q.push(node->left);
                    parent[node->left]=node;
                }
                if(node->right)
                {
                    q.push(node->right);
                    parent[node->right]=node;
                }
            }
        }
        return target;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode* ,TreeNode*> parent;
        TreeNode* target=markParent(root,parent,start);

        unordered_map<TreeNode*,bool>visited;
        visited[target]=true;
        queue<TreeNode*> q;
        q.push(target);
        int time=-1;
        while(q.size()!=0)
        {
            time++;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(parent[node] && !visited[parent[node]])
                {
                    q.push(parent[node]);
                    visited[parent[node]]=true;
                }
                if(node->left && !visited[node->left])
                {
                    q.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right && !visited[node->right])
                {
                    q.push(node->right);
                    visited[node->right]=true;
                }
            }
        }
        return time;
        
    }
};
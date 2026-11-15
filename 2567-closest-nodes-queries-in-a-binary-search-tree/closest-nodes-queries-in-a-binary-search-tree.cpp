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
    vector<int> arr;

    void inorder(TreeNode* root)
    {
        if(!root) return;

        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries)
    {
        inorder(root);

        vector<vector<int>> ans;

        for(int q : queries)
        {
            auto it = lower_bound(arr.begin(), arr.end(), q);

            int mini = -1, maxi = -1;

            if(it != arr.end())
                maxi = *it;

            if(it != arr.end() && *it == q)
                mini = q;
            else if(it != arr.begin())
                mini = *(it - 1);

            ans.push_back({mini, maxi});
        }

        return ans;
    }
};

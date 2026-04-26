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
    void traverse(TreeNode* node)
    {
        if(node==NULL)  return;
        traverse(node->left);
        arr.push_back(node->val);
        traverse(node->right);
    }
    TreeNode* buildTree(vector<int> &arr,int l,int r)
    {
        if(l>r) return NULL;
        int mid=(l+r)/2;
        TreeNode* node=new TreeNode(arr[mid]);
        node->left=buildTree(arr,l,mid-1);
        node->right=buildTree(arr,mid+1,r);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
       traverse(root) ;
       int l=0,r=arr.size()-1;
       return buildTree(arr,l,r);
    }
};
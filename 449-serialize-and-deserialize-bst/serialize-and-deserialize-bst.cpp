/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string res;
    void traverse( TreeNode *node)
    {
        if(node==NULL)  return ;
        res +=to_string(node->val);
        res+=",";
        traverse(node->left);
        traverse(node->right);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root==NULL) return "";
        traverse(root);
        return res;
    }
    int i=0;
    TreeNode* arrToBST(vector<int> &inorder,int minVal,int maxVal)
    {
        if(i>=inorder.size())   return NULL;
        int val=inorder[i];
        if(val<minVal ||val>maxVal) return NULL;
        i++;//important update after confirming
        TreeNode* root=new TreeNode(val);
        root->left=arrToBST(inorder,minVal,val);
        root->right=arrToBST(inorder,val,maxVal);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="")    return NULL;
        stringstream ss(data);
        string str;
        vector<int> inorder;
        while(getline(ss,str,','))
        {
            inorder.push_back(stoi(str));
        }
        return arrToBST(inorder,INT_MIN,INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
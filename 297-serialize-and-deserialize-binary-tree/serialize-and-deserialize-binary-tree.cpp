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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)  return "";
        string res="";
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()!=0)
        {
            TreeNode* node=q.front();
            q.pop();
            if(node)
            {
                res+=to_string(node->val)+",";
                q.push(node->left);
                q.push(node->right);
            }
            else    res+="N,";
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data=="")   return NULL;
        stringstream ss(data);
        string str;
        getline(ss,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()!=0)
        {
            TreeNode* node=q.front();
            q.pop();
            getline(ss,str,',');
            if(str!="N")
            {
                node->left=new TreeNode(stoi(str));
                q.push(node->left);
            }
            getline(ss,str,',');
            if(str!="N")
            {
                node->right=new TreeNode(stoi(str));
                q.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
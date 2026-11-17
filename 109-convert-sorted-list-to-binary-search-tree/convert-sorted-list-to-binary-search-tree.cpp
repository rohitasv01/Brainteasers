/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* build(ListNode* &temp,int n )
    {
        if(n<=0)    return NULL;
        TreeNode* left=build(temp,n/2);
        TreeNode* root=new TreeNode(temp->val);
        temp=temp->next;
        TreeNode* right=build(temp,n-n/2 -1);
        root->left=left;
        root->right=right;
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* temp=head;
        int n=0;
        while(temp)
        {
            temp=temp->next;
            n++;
        }
        return build(head,n);
    }
};
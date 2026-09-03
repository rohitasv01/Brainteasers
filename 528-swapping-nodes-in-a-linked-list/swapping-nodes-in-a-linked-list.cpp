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
class Solution {
public:
    //move fast k steps then move slow and fast together when fast reaches null we reached kth last 
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* fast=head;
        ListNode* slow=head;
        for(int i=0;i<k;i++)
        {
            fast=fast->next;
        }
        while(fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        fast=head;
        for(int i=1;i<k;i++)    fast=fast->next;
        swap(slow->val,fast->val);
        return head;
    }
};
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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr=head->next;
        ListNode* dummy=new ListNode(-1);
        ListNode* currB=dummy;
        int sum=0;
        while(curr)
        {
            if(curr->val==0)
            {
                ListNode* builderNode=new ListNode(sum);
                sum=0;
                currB->next=builderNode;
                currB=builderNode;
            }
            else    sum+=curr->val;
            curr=curr->next;
        }
        return dummy->next;
    }
};
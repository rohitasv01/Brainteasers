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
    ListNode* reverseLL(ListNode* head)
    {
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr)
        {
            ListNode* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* newHead=reverseLL(head);
        ListNode* curr=newHead;
        ListNode* dummy=new ListNode(-1);
        ListNode* prev=dummy;
        int carry=0;
        while(curr || carry)
        {
            int mul=carry;
            if(curr)    mul+=2*curr->val;
            ListNode* newNode=new ListNode(mul%10);
            prev->next=newNode;
            prev=newNode;
            if(curr)    curr=curr->next;
            carry=mul/10;
        }
        return reverseLL(dummy->next);
    }
};
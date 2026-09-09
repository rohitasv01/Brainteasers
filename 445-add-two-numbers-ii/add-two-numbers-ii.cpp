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
    //reverse->add->reverse
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* n1=reverseLL(l1);
        ListNode* n2=reverseLL(l2);
        ListNode* dummy=new ListNode(-1,NULL);
        ListNode* temp=dummy;
        int carry=0;
        while(n1 || n2 || carry) 
        {
            int sum=carry;
            if(n1)  sum+=n1->val;
            if(n2)  sum+=n2->val;
            ListNode* nextNode=new ListNode(sum%10);
            temp->next=nextNode;
            temp=nextNode;
            carry=sum/10;
            if(n1) n1=n1->next;
            if(n2)  n2=n2->next;
        }
        return reverseLL(dummy->next);
    }
};

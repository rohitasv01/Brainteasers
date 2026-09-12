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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int groupSize=1;
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr)
        {
            int count=0;
            ListNode* ahead=curr;
            while(ahead && count<groupSize)
            {
                count++;
                ahead=ahead->next;
            }
            if(count%2==1) 
            {
                for(int i=0;i<count;i++)
                {
                    prev=curr;
                    curr=curr->next;
                }
            }
            else
            {
                ListNode* reqNode=curr;
                for(int i=1;i<count;i++)
                {
                    ListNode* nextNode=curr->next;
                    curr->next=nextNode->next;
                    nextNode->next=prev->next;
                    prev->next=nextNode;
                }
                prev=reqNode;
                curr=ahead;
            }
            groupSize++;
        }
        return head;
    }
};
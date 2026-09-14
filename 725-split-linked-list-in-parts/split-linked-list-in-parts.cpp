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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr=head;
        int length=0;
        while(curr) 
        {
            curr=curr->next;
            length++;
        }
        int size=length/k;
        curr=head;
        ListNode* prev=NULL;
        vector<ListNode*> ans;
        int no=0;
        while(curr)
        {
            for(int i=0;i<length%k;i++)
            {
                ans.push_back(curr);
                no++;
                for(int i=0;i<size+1;i++)
                {
                    prev=curr;
                    curr=curr->next;
                }
                prev->next=NULL;
            }
            while(no<k)
            {
                ans.push_back(curr);
                no++;
                for(int i=0;i<size;i++)
                {
                    prev=curr;
                    curr=curr->next;
                }
                prev->next=NULL;
            }
        }
        while(no<k)
        {
            ans.push_back(NULL);
            no++;
        }
        return ans;
    }
};
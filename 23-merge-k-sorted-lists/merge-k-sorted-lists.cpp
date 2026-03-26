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
    struct compare
    {
        bool operator()(ListNode *a,ListNode *b)
        {
            return (a->val >b->val);
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       priority_queue<ListNode*,vector<ListNode*>,compare> minHeap;
       for(auto node:lists)
       {
            if(node)    minHeap.push(node);
       }
    
    ListNode* dummy=new ListNode(-1);
    ListNode*tail=dummy;
    while(minHeap.size()!=0)
    {
        ListNode* smallestNode=minHeap.top();
        minHeap.pop();
        tail->next=smallestNode;
        tail=smallestNode;
        if(smallestNode->next)   minHeap.push(smallestNode->next);
    }
    return dummy->next;
    }
};
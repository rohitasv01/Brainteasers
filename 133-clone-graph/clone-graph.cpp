/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)   return node;
        unordered_map<Node*, Node*> mpp;
        Node* clone=new Node(node->val);
        mpp[node]=clone;
        queue<Node*> q;
        q.push(node);
        while(q.size())
        {
            Node* curr=q.front();
            q.pop();
            for(auto neighbor:curr->neighbors)
            {
                if(mpp.find(neighbor)==mpp.end())
                {
                    mpp[neighbor]=new Node(neighbor->val);
                    q.push(neighbor);
                }
                mpp[curr]->neighbors.push_back(mpp[neighbor]);
            }
        }
        return mpp[node];
    }
};
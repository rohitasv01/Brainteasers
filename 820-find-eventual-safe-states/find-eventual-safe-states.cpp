class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> rev(n);
        vector<int> indegree(n,0);
        for(int u=0;u<n;u++)
        {
            for(int v:graph[u])
            { 
                rev[v].push_back(u);
                indegree[u]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)  q.push(i);
        }
        vector<int> ans;
        while(q.size())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int neighbour :rev[node])
            {
                indegree[neighbour]--;
                if(indegree[neighbour]==0)  q.push(neighbour);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1) 
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> visited(n,false);
        int provinces=0;
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                q.push(i);
                provinces++;
                while(q.size())
                {
                    int node=q.front();
                    q.pop();
                    visited[node]=true;
                    for(int neighbour:adj[node])
                    {
                        if(!visited[neighbour])
                        {
                            q.push(neighbour);
                            visited[neighbour]=true;
                        }
                    }
                }
            }
        }
        return provinces;
    }
};
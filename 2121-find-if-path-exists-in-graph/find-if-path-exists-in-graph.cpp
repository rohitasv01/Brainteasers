class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for(auto e:edges)
        {
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>visited(n,-1);
        queue<int>q;
        q.push(source);
        visited[source]=1;
        while(q.size())
        {
            int node=q.front();
            q.pop();
            for(int neighbour:adj[node])
            {
                if(visited[neighbour]==-1)
                {
                    q.push(neighbour);
                    visited[neighbour]=1;
                }
            }
        }
        return (visited[destination]==1)?true :false;
    }
};
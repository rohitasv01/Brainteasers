class Solution {
public:
    int bfs(int i,vector<int>&visited,vector<vector<int>>& adj)
    {
        visited[i]=1;
        queue<int>q;
        q.push(i);
        int count =0;
        while(q.size())
        {
            int edge=q.front();
            q.pop();
            count++;
            for(int neighbour:adj[edge])
            {
                if(visited[neighbour] ==-1)
                {
                    q.push(neighbour);
                    visited[neighbour]=1;
                }
            }
        }
        return count;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto &edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> visited(n,-1);
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==-1)
            {
                int count=bfs(i,visited,adj);
                sum+=(long long)(n-count)*count;
            }
        }
        return sum/2;
    }
};
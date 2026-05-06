class Solution {
public:
    bool dfs(int i,vector<vector<int>>& adj,vector<int> &color)
    {
        for(auto neighbour:adj[i])
        {
            if(color[neighbour]==-1)
            {
                color[neighbour]=1-color[i];
                if(!dfs(neighbour,adj,color))   return false;
            }
            else if(color[neighbour]==color[i]) return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color(n+1,-1);
        vector<vector<int>>adj(n+1);
        for(auto ed:dislikes)
        {
            int u=ed[0];
            int v=ed[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=1;i<=n;i++)
        {
            if(color[i]==-1)
            {
                color[i]=0;
                if(!dfs(i,adj,color))   return false;
            }
        }
        return true;
    }
};
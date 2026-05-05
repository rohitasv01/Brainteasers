class Solution {
public:
    bool dfs(int node,vector<vector<int>>&graph,vector<int>& color)
    {
        for(auto neighbour: graph[node])
        {
            if(color[neighbour]==-1)
            {
                color[neighbour]=1-color[node];
                if(!dfs(neighbour,graph,color)) return false;
            }
            else
            {
                if(color[neighbour]==color[node])   return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        bool bi;
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                color[i]=0;
                bi=dfs(i,graph,color);
                if(bi==false)   return false;
            }
        }
        return true;
    }
};
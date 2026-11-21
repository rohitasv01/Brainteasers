class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size()+2;
        vector<vector<int>> adj(n);
        for(auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=1;i<=n;i++)
        {
            if(adj[i].size()==n-2)  return i;
        }
        return -1;
    }
};
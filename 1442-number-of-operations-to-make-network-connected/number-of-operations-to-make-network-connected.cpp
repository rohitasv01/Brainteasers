class Solution {
public:

    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited)
    {
        visited[node] = 1;

        for(auto neighbour : adj[node])
        {
            if(!visited[neighbour])
            {
                dfs(neighbour, adj, visited);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {

        // Not enough edges
        if(connections.size() < n-1)
            return -1;

        // Build graph
        vector<vector<int>> adj(n);

        for(auto it : connections)
        {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Visited array
        vector<int> visited(n,0);

        int components = 0;

        // Count connected components
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                components++;
                dfs(i, adj, visited);
            }
        }

        // Minimum cables needed
        return components - 1;
    }
};
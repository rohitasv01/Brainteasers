class Solution {
public:
    bool dfs(int i,vector<int> &visited,vector<int> & pathVisited,vector<int> & safe,vector<vector<int>>& graph)
    {
        visited[i]=1;
        pathVisited[i]=1;
        for(int neighbour:graph[i])
        {
            if(visited[neighbour]==0)
            {
                if(dfs(neighbour,visited,pathVisited,safe,graph))
                return true;
            }
            else if(pathVisited[neighbour]) return true;
        }
        safe[i]=1;
        pathVisited[i]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> visited(n,0);
        vector<int> pathVisited(n,0);
        vector<int> safe(n,0);
        for(int i=0;i<n;i++)
        {
            if(!visited[i]) dfs(i,visited,pathVisited,safe,graph);
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(safe[i]==1)  ans.push_back(i);
        }
        return ans;
    }
};
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>>adj(n+1);
        vector<int>indegree(n+1,0);
        for(auto it:trust)
        {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        for(int i=1;i<n+1;i++)
        {
            if(indegree[i]==n-1 && adj[i].size()==0)  return i;
        }
        return -1;
    }
};
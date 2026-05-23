class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n=numCourses;
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++)     dist[i][i]=0;
        for(auto it:prerequisites)   dist[it[0]][it[1]]=1;
        for(int via=0;via<n;via++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(dist[i][via]==INT_MAX || dist[via][j]==INT_MAX)  continue;
                    dist[i][j]=min(dist[i][j],dist[i][via]+dist[via][j]);
                }
            }
        }
        vector<bool>ans;
        for(auto it:queries)
        {
            if(dist[it[0]][it[1]]==INT_MAX)     ans.push_back(false);
            else    ans.push_back(true);
        }
        return ans;
    }
};
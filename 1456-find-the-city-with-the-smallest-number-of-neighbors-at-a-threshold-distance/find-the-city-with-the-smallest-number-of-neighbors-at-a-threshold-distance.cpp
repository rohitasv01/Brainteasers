class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>>adj(n);
        vector<vector<int>>distance(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++)    distance[i][i]=0;
        for(auto it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
            distance[it[0]][it[1]]=it[2];
            distance[it[1]][it[0]]=it[2];
        }
        for(int via=0;via<n;via++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(distance[i][via]==INT_MAX || distance[via][j]==INT_MAX)  continue;
                    distance[i][j]=min(distance[i][j],distance[i][via]+distance[via][j]);
                }
            }
        }
        vector<int>number(n,-1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(distance[i][j]<=distanceThreshold)   number[i]++;
            }
        }
        int node=-1,mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(number[i] <= mini)
            {
                node=i;
                mini=number[i];
            }
        }
        return node;
    }
};
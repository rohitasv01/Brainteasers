class Solution {
public:
/*-make a disjoint set, of 1's and put in all 1 in all 4 directions
-for all 0's try to make ot 1 and get all the parent of neighbour in set
*/
    class DisjointSet
    {
        public:
        vector<int> parent,size;
        DisjointSet(int n)
        {
            parent.resize(n+1);
            size.resize(n+1,1);
            for(int i=0;i<=n;i++)   parent[i]=i;
        }
        int findParent(int node)
        {
            if(parent[node]==node)  return node;
            return parent[node]=findParent(parent[node]);
        }
        void unionBySize(int u,int v)
        {
            int pu=findParent(u);
            int pv=findParent(v);
            if(pu==pv)  return;
            if(size[pu]<size[pv])
            {
                parent[pu]=pv;
                size[pv]+=size[pu];
            }
            else 
            {
                parent[pv]=pu;
                size[pu]+=size[pv];
            }
        }
    };
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    int dx[4]={1,0,-1,0};
                    int dy[4]={0,1,0,-1};
                    int x=i,y=j;
                    for(int i=0;i<4;i++)
                    {
                        int nx=x+dx[i];
                        int ny=y+dy[i];
                        if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==1)
                        {
                            int nodeNo=x*n+y;
                            int neighbourNodeNo=nx*n+ny;
                            ds.unionBySize(nodeNo,neighbourNodeNo);
                        }
                    }
                }
            }
        } 
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {   
                unordered_set<int> components;
                if(grid[i][j]==0)
                {
                    int dx[4]={1,0,-1,0};
                    int dy[4]={0,1,0,-1};
                    int x=i,y=j;
                    for(int i=0;i<4;i++)
                    {
                        int nx=x+dx[i];
                        int ny=y+dy[i];
                        if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==1)
                        {
                            int nodeNo=x*n+y;
                            int neighbourNodeNo=nx*n+ny;
                            components.insert(ds.findParent(neighbourNodeNo));
                        }
                    }
                    int totalSize=1;
                    for(auto it:components) totalSize+=ds.size[it];
                    maxi=max(maxi,totalSize);
                }
            }
        } 
        //whole grid may be 1
        if(maxi==0) return n*n;
        else return maxi;
    }
};
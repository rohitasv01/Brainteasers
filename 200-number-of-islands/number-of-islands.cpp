class Solution {
    /*
    -traverse all elements ,if it is 1 then traverse in all 4 direction traversing it 
    -then again traverse all the elements of grid ,then if it is 1 and if correponding node is itself parent inrease count
    */
public:
    class DisjointSet
    {
        public:
        vector<int> parent,size;
        DisjointSet(int n) //constructor
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
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        DisjointSet ds(n*m);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int x=i,y=j;
                if(grid[x][y]=='1')
                {
                    int dx[4]={1,0,-1,0};
                    int dy[4]={0,1,0,-1};
                    for(int i=0;i<4;i++)
                    {
                        int nx=x+dx[i];
                        int ny=y+dy[i];
                        if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]=='1') 
                        {
                            int nodeNo=x*m+y;
                            int neighbourNodeNo=nx*m+ny;
                            ds.unionBySize(nodeNo,neighbourNodeNo);
                        }
                    }
                }
            }
        } 
        int islands=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    int nodeNo=i*m+j;
                    if(ds.findParent(nodeNo)==nodeNo)  islands++;
                }
            }
        }
        return islands;
    }
};
class Solution {
public:
    class DisjointSet
    {
        public:
        vector<int> parent,size;
        DisjointSet(int n)
        {
            parent.resize(n+1);
            size.resize(n+1,1);
            for(int i=0;i<n;i++)    parent[i]=i;
        }
        int findParent(int node)
        {
            if(node==parent[node])  return node;
            return parent[node]=findParent(parent[node]);
        }
        void unionBySize(int u,int v)
        {
            int pu=findParent(u);
            int pv=findParent(v);
            if(pu==pv)  return ;
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extra=0,components=0;
        for(auto it:connections)
        {
            int u=it[0];
            int v=it[1];
            if(ds.findParent(u)==ds.findParent(v))  extra++;
            else    ds.unionBySize(u,v);
        }
        for(int i=0;i<n;i++)    
        {
            if(ds.parent[i]==i)    components++;
        }
        if(extra>=components-1)   return components-1;
        else return -1;
    }
};
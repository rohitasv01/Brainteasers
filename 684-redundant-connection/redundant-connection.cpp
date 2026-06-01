class Solution {
public:
    class DisjointSet
    {
        public:
        vector<int> parent,size;
        DisjointSet(int n)//constructor
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>ans;
        DisjointSet ds(n);
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            if(ds.findParent(u)==ds.findParent(v))  ans={u,v};
            else    ds.unionBySize(u,v);
        }
        return ans;
    }
};
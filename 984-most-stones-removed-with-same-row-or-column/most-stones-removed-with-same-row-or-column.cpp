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
    int removeStones(vector<vector<int>>& stones) {
        int maxRow=0,maxCol=0,components=0;
        for(auto it:stones)
        {
            maxRow=max(maxRow,it[0]);
            maxCol=max(maxCol,it[1]);
        }
        unordered_set<int> usedIndex;
        DisjointSet ds(maxRow+maxCol+1);
        for(auto it:stones)
        {
            int rowIndex=it[0];
            int colIndex=it[1]+maxRow+1;
            ds.unionBySize(rowIndex,colIndex);
            usedIndex.insert(rowIndex);
            usedIndex.insert(colIndex);
        }
        for(auto node:usedIndex)
        {
            if(ds.parent[node]==node)   components++;
        }
        return stones.size()-components;
    }
};
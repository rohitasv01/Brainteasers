class Solution {
public:
/*make 2 dsu for alice and bob
process type 3 first hen 1,2 
then count no of edges that do not connect any new edges,
in type 3 processing do not reduce redundant twice
intially components of both alice and bob should be n and they shound become 1 at end if not return -1
*/
    class DisjointSet
    {
        public :
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
            if (pu==pv) return ;
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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet dsA(n);
        DisjointSet dsB(n);
        int componentsA=n,componentsB=n,redundant=0;
        for(auto it:edges)
        {
            int type=it[0];
            int u=it[1];
            int v=it[2];
            if(type==3)
            {
                if(dsA.findParent(u)==dsA.findParent(v) && dsB.findParent(u)==dsB.findParent(v))     
                //checking any one is sufficient as they will occur together
                redundant++;
                else
                {
                    dsA.unionBySize(u,v);
                    componentsA--;
                    dsB.unionBySize(u,v);
                    componentsB--;
                }
            }
        }
        for (auto it:edges)
        {
            int type=it[0];
            int u=it[1];
            int v=it[2];
            if(type==1)
            {
                if(dsA.findParent(u)==dsA.findParent(v))    redundant++;
                else
                {
                    dsA.unionBySize(u,v);
                    componentsA--;
                }
            }
             if(type==2)
            {
                if(dsB.findParent(u)==dsB.findParent(v))    redundant++;
                else
                {
                    dsB.unionBySize(u,v);
                    componentsB--;
                }
            }
        }
        if(componentsA ==1 && componentsB==1)   return redundant;
        else return -1;
    }
};
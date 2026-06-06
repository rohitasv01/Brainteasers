class Solution {
public:
    class DisjointSet
    {
        public :
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
    bool equationsPossible(vector<string>& equations) {
        DisjointSet ds(26);
        int n=equations.size();
        //check in two pass not one -because in 1 pass we may get false positives
        for(int i=0;i<n;i++)
        {
            if(equations[i][1]=='=')    ds.unionBySize(equations[i][0]-'a',equations[i][3]-'a');
        }
        for(int i=0;i<n;i++)
        {
            if(equations[i][1]=='!')
            {
                if(ds.findParent(equations[i][0]-'a')==ds.findParent(equations[i][3]-'a'))  return false; 
            }
        }
        return true;
    }
};
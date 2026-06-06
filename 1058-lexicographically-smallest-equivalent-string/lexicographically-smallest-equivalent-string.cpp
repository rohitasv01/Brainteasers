class Solution {
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
        void unionLexicographically(int u,int v)
        {
            int pu=findParent(u);
            int pv=findParent(v);
            if(pu==pv)  return;
            if(pu<pv)   parent[pv]=pu;
            else parent[pu]=pv;
        }
    };
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DisjointSet ds(26);
        int n=s1.size();
        for(int i=0;i<n;i++)
        {
            ds.unionLexicographically(s1[i]-'a',s2[i]-'a');
        }
        string ans;
        for(auto it:baseStr)
        {
            ans+=(ds.findParent(it-'a')+'a');
        }
        return ans;
    }
};
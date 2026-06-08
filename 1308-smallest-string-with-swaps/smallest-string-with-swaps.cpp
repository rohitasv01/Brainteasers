class Solution {
public:
/* dsu all connected notes 
group all of them py parents
sort index and chahrcters and the assign*/
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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        DisjointSet ds(n);
        string ans=s;
        for(auto it :pairs) ds.unionBySize(it[0],it[1]);
        unordered_map <int,vector<int>> connections;
        for(int i=0;i<n;i++)
        {
            int parent=ds.findParent(i);
            connections[parent].push_back(i);
        }
        for(auto it:connections)
        {
            vector<int> indices=it.second;
            string temp="";
            for(auto it:indices)   temp+=s[it] ;
            sort(indices.begin(),indices.end());
            sort(temp.begin(),temp.end());
            for(int i=0;i<indices.size();i++)  ans[indices[i]]=temp[i] ;
        }
        return ans;
    }
};
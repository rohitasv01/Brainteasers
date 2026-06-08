class Solution {
public:
/* make DSU of factors of each number 
then traverse all the nodes and find maximum of size of all the elements
*/
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
    int largestComponentSize(vector<int>& nums) {
        
        int maxElement=*max_element(nums.begin(),nums.end());
        DisjointSet ds(maxElement);
        for(auto it: nums)
        {
            for(int i=2;i*i<=it;i++)
            {
                if(it%i==0)
                {
                    ds.unionBySize(it,i);
                    ds.unionBySize(it,it/i);
                }
            }
        }
        unordered_map<int,int> freq;
        for(auto it:nums)
        {
            int parent=ds.findParent(it);
            freq[parent]++;
        }
        int maxi=0;
        for(auto [parent,frequency]:freq)   maxi=max(maxi,frequency);
        return maxi;
    }
};
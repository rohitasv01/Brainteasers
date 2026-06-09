class Solution {
public:
/* if time can be done in ascending orger everyting will be easier
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
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(),meetings.end(),    
        [](vector<int> &a,vector<int> &b)
        {
            return a[2]<b[2];
        }
        );
        DisjointSet ds(n);
        ds.unionBySize(0,firstPerson);
        int i=0;
        while(i<meetings.size())
        {
            int time=meetings[i][2];
            vector<int> peopleWithMeetingAtSameTime={};
            int j=i;
            while(j<meetings.size() && meetings[j][2]==time)
            {
                int u=meetings[j][0],v=meetings[j][1];
                peopleWithMeetingAtSameTime.push_back(u);
                peopleWithMeetingAtSameTime.push_back(v);
                ds.unionBySize(u,v);
                j++;
            }
            int secretParent=ds.findParent(0);
            for(int person:peopleWithMeetingAtSameTime)
            {
                if(ds.findParent(person)!=secretParent)
                {
                    ds.parent[person]=person;
                    ds.size[person]=1;
                }
            }
            i=j;
        }
        vector<int>ans;
        int secretParent=ds.findParent(0);
        for(int i=0;i<n;i++)
        {
            if(ds.findParent(i)==secretParent)  ans.push_back(i);
        }
        return ans;
    }
};
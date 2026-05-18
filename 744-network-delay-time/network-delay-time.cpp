class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it:times)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> time(n+1,INT_MAX);
        time[k]=0;
        //time,node;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        while(pq.size())
        {
            auto[t,node]=pq.top();
            pq.pop();
            if(t>time[node]) continue;
            for(auto [neighbour,wt]:adj[node])
            {
                if(wt+time[node]<time[neighbour])
                {
                    time[neighbour]=wt+time[node];
                    //t -instead of time[node]
                    pq.push({time[neighbour],neighbour});
                }
            }
        }
        int maxi=0;
        for(int i=1;i<=n;i++)
        {
            if(time[i]==INT_MAX) return -1;
            maxi=max(time[i],maxi);
        }
        return maxi;
    }
};
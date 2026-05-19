class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n=passingFees.size();
        vector<vector<pair<int,int>>> adj(n);
        for(auto it: edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        //fees,time,node
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        pq.push({passingFees[0],0,0});
        vector<int> time(n,INT_MAX);
        time[0]=0;
        int cost=INT_MAX;
        while(pq.size())
        {
            auto[fees,t,node]=pq.top();
            pq.pop();
            if(t>maxTime)   continue;
            if (node==n-1)  return fees;
            for(auto[neighbour,weight]:adj[node])
            {
                if(t+weight<time[neighbour])
                {
                    time[neighbour]=t+weight;
                    pq.push({fees+passingFees[neighbour],t+weight,neighbour});
                }
            }
        }
        return -1;
    }
};
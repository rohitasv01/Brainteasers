class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long>distance(n,LLONG_MAX);
        vector<int>ways(n,0);
        distance[0]=0;
        ways[0]=1;
        int mod=(int)(1e9+7);
        //distance,node
        priority_queue<pair<long long,int>, vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        while(pq.size())
        {
            auto[dis,node]=pq.top();
            pq.pop();
            if(dis>distance[node])  continue;
            for(auto[neighbour,wt]:adj[node])
            {
                if(wt+dis<distance[neighbour])
                {
                    distance[neighbour]=wt+dis;
                    pq.push({wt+dis,neighbour});
                    ways[neighbour]=ways[node];
                }
                else if(wt+dis==distance[neighbour])
                {
                    ways[neighbour]=(ways[neighbour]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};
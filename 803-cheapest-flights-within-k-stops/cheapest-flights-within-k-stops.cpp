class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<tuple<int,int,int>> q;
        //<stops,node,currCost>
        q.push({0,src,0});
        vector<int>cost(n,INT_MAX);
        cost[src]=0;
        while(q.size())
        {
            auto[stops,node,currCost]=q.front();
            q.pop();
            if (stops>k)    continue;
            for(auto[neighbour,price]:adj[node])
            {
                if(currCost+price <cost[neighbour])
                {
                    cost[neighbour]=price+currCost;
                    q.push({stops+1,neighbour,cost[neighbour]});
                }
            }
        }
        if(cost[dst]==INT_MAX)  return -1;
        else return cost[dst];
    }
};
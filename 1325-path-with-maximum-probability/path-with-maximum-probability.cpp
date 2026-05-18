class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb,
                          int start_node, int end_node) {

        vector<vector<pair<int,double>>> adj(n);

        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            double prob=succProb[i];

            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});
        }

        vector<double> probability(n,0.0);

        priority_queue<pair<double,int>> pq;
        // {probability,node}

        pq.push({1.0,start_node});
        probability[start_node]=1.0;

        while(pq.size())
        {
            auto [prob,node]=pq.top();
            pq.pop();

            if(node==end_node)
                return prob;

            if(prob < probability[node])
                continue;

            for(auto [neighbour,edgeProb]:adj[node])
            {
                double newProb=prob*edgeProb;

                if(newProb > probability[neighbour])
                {
                    probability[neighbour]=newProb;
                    pq.push({newProb,neighbour});
                }
            }
        }

        return 0.0;
    }
};
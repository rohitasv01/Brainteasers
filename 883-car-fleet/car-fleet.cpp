class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> cars;// position ,time
        for(int i=0;i<speed.size();i++)
        {
            int pos=position[i];
            double time=(double)(target-position[i])/speed[i];
            cars.push_back({pos,time});
        }
        sort(cars.rbegin(),cars.rend());
        double maxTime=0;
        int fleets=0;
        for(int i=0;i<cars.size();i++)
        {
            double time=cars[i].second;
            if(time>maxTime)
            {
                fleets++;
                maxTime=time;
            }
        }
        return fleets;
    }
};
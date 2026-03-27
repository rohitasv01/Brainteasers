class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0)  return false;
        map<int ,int>  freq;
        for(int i:hand)     freq[i]++;
        while(freq.size()!=0)
        {
            int current=freq.begin()->first;
            for(int i=0;i<groupSize;i++)
            {
                if(freq[current+i]==0)  return false;
                freq[current+i]--;
                if(freq[current+i]==0) freq.erase(current+i);
            }
        }
        return true;
    }
};
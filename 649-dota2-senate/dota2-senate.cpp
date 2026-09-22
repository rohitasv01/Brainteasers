class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r,d;
        int n=senate.size();
        for(int i=0;i<n;i++)
        {
            if(senate[i]=='R')  r.push(i);
            else    d.push(i);
        }
        while(r.size() && d.size())
        {
            int radiant=r.front();
            int dire=d.front();
            d.pop();
            r.pop();
            if(radiant<dire)    
            {
                r.push(radiant+n); 
            }
            else
            {
                d.push(dire+n);
            }
        }
        return r.size()? "Radiant":"Dire";
    }
};
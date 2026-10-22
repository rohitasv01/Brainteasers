class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> qr;
        queue<int> qd;
        int n=senate.size();
        for(int i=0;i<senate.size();i++)
        {
            if(senate[i]=='R')  qr.push(i);
            else qd.push(i);
        }
        while(qr.size() && qd.size())
        {
            int r=qr.front();
            int d=qd.front();
            qr.pop();
            qd.pop();
            if(r<d)  qr.push(r+n);
            else qd.push(d+n);
            
        }
        if(qr.size())   return "Radiant";
        return "Dire";
    }
};
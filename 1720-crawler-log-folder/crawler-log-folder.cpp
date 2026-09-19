class Solution {
public:
    int minOperations(vector<string>& logs) {
        int level=0;
        for(string s:logs)
        {
            if(s=="../" )   
            {
                if(level)   level--;
            }
            else if(s=="./")    continue;
            else level++;
        }
        return level;
    }
};
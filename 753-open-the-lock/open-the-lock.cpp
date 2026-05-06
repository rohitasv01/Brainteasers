class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited(deadends.begin(),deadends.end());
        if(visited.find("0000")!=visited.end()) return -1;
        queue<string>q;
        q.push("0000");
        visited.insert("0000");
        int turns=-1;
        while(q.size())
        {
            int size=q.size();
            turns++;
            for(int i=0;i<size;i++)
            {
                string lock=q.front();
                q.pop();
                if(lock==target)    return turns;
                for(int j=0;j<4;j++)
                {
                    string up=lock;
                    up[j]=(lock[j]=='9')? '0':lock[j]+1;
                    string down=lock;
                    down[j]=(lock[j]=='0')?'9':lock[j]-1;
                     if(visited.count(up)==0)
                    {
                        q.push(up);
                        visited.insert(up);
                    }
                    if(visited.count(down)==0)
                    {
                        q.push(down);
                        visited.insert(down);
                    }
                }
            }
        }
        return -1;
    }
};
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>visited(n,-1);
        queue<int>q;
        q.push(0);
        visited[0]=1;
        while(q.size())
        {
            int room=q.front();
            q.pop();
            for(auto open:rooms[room])
            {
                if(visited[open]==-1)
                {
                    q.push(open);
                    visited[open]=1;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(visited[i]==-1)  return false;
        }
        return true;
    }
};
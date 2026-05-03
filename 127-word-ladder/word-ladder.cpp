class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        if(st.find(endWord)==st.end())  return 0;
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(q.size())
        {
            auto[word,level]=q.front();
            q.pop();
            if(word==endWord)   return level;
            for(int i=0;i<word.size();i++)
            {
                string temp=word;
                for(char ch='a';ch<='z';ch++)
                {
                    temp[i]=ch;
                    if (st.find(temp)!=st.end())
                    {
                        q.push({temp,level+1});
                        st.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};
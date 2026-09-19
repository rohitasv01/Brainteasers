class Solution {
public:
    int minLength(string s) {
        string ans;
        for( char ch :s)
        {
            if(ans.size() && ((ans.back()=='A' && ch=='B') ||(ans.back()=='C' && ch=='D')) )   ans.pop_back();
            else ans.push_back(ch);
        }
        return ans.size();
    }
};
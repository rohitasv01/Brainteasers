class Solution {
public:
//
    string reverseVowels(string s) {
        string vowels="";
        for(auto it: s)
        {
            if(it=='a'||it=='e'||it=='i'||it=='o'||it=='u'||it=='A'||it=='E'||it=='I'||it=='O'||it=='U' )
            {
                vowels+=it;
            }
        }
        reverse(vowels.begin(),vowels.end());
        int p1=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a' ||s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u' ||s[i]=='A' ||s[i]=='E' ||s[i]=='I' ||s[i]=='O' ||s[i]=='U' )    
            {
                s[i]=vowels[p1];
                p1++;
            }
        }
        return s;
    }
};
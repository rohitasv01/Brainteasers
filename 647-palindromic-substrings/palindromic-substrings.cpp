class Solution {
public: 
    bool isPalindrome(string s)
    {
        int l=0,r=s.size()-1;
        while(l<r)
        {
            if(s[r]!=s[l])  return false;
            l++;
            r--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int n=s.size(),count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(isPalindrome(s.substr(i,j-i+1))) count++;
            }
        }
        return count;
    }
};
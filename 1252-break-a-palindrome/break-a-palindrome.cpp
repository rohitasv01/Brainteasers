class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n=palindrome.size();
        if(n==1)    return "";
        string temp=palindrome;
        bool change=false;
        for(int i=0;i<n/2;i++)
        {
            if(temp[i]!='a')
            {
                temp[i]='a';
                change =true;
                break;
            }
        }
        if(!change) temp[n-1]='b';
        return temp;
    }
};
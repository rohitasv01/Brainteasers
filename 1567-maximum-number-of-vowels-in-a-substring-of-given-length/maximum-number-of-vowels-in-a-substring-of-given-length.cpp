class Solution {
public:
    bool isVowel(char c)
    {
        if(c=='a'|| c=='e'|| c=='i'|| c=='o' ||c=='u')  return true;
        else return false;
    }
    int maxVowels(string s, int k) {
        int maxi=0,vowels=0;
        for(int i=0;i<k-1;i++)  
        {
            if(isVowel(s[i]))   vowels++;
        }
        int n=s.size();
        for(int i=k-1;i<n;i++)
        {
            if(isVowel(s[i]))   vowels++;
            maxi=max(maxi,vowels);
            if(isVowel(s[i-(k-1)])) vowels--;
        }
        return maxi;
    }
};
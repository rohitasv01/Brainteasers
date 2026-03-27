class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       vector<int> frequency(26,0);
       for(char ch:tasks)   frequency[ch-'A']++;
       sort(frequency.begin(),frequency.end());
       int maxFrequency=frequency[25];
       int countMax=1;
       for(int i=24;i>=0;i--)
       {
        if(frequency[i]==maxFrequency)  countMax++;
        else break;
       } 
       return max((int)tasks.size(),(maxFrequency-1)*(n+1)+countMax);
    }
};
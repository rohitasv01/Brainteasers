class Solution {
public:
    string intToRoman(int num) {
        vector<char>arr1 ={'I','X','C','M'};
        vector<char>arr5 ={'V','L','D'};
        string res="";
        int place=-1;
        int n=num;
        while(n>0)
        {
            int dig=n%10;
            n/=10;
            place++;
            string temp = "";
            if(place == 3)
             {
                temp += string(dig, 'M');
            }
            else 
            {
                if(dig == 9)  temp += string(1, arr1[place]) + string(1, arr1[place+1]);
                else if(dig >= 5) {
                    temp += string(1, arr5[place]);
                    temp += string(dig - 5, arr1[place]);
                }
                else if(dig == 4) temp += string(1, arr1[place]) + string(1, arr5[place]);
                else temp += string(dig, arr1[place]);
            }

            res = temp + res;
        }
        return res;
    }
};
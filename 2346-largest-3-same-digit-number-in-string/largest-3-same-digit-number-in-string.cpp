class Solution {
public:
    string largestGoodInteger(string num) 
    {
        int maxi = -1;
        for(int i=0; i<num.length()-2; i++)
        {
            bool valid = true;
            char ch = num[i];
            for(int j=i+1; j<i+3; j++)
            {
                if(num[j] != ch) valid = false;
            }
            if(valid) maxi = max(maxi, ch-'0');
        }

        string ans(3, maxi+'0');
        return maxi == -1 ? "" : ans;
    }
};
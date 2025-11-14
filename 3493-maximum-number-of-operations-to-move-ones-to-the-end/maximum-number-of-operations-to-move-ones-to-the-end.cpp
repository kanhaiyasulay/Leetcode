class Solution {
public:
    int maxOperations(string s) 
    {
        int cnt1 = 0, cntOpt = 0;
        int n = s.length();

        for(int i=0; i<n; i++)
        {
            if(s[i] == '1') 
            {
                cnt1++;
                continue;
            }
            else
                 cntOpt += cnt1;

            int j = i;
            while(j < n && s[j] == '0') j++;
            i = j-1;
        }    

        return cntOpt;
    }
};
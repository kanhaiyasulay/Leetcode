class Solution {
public:
    int MOD = 1e9 + 7;
    int numSub(string s) 
    {
        int runSum = 0;
        int cnt = 0;

        for(int i=0; i<s.length(); i++)    
        {
            if(s[i] == '1') runSum++;
            else runSum = 0;
            cnt += runSum;
            cnt %= MOD;
        }

        return cnt;
    }
};
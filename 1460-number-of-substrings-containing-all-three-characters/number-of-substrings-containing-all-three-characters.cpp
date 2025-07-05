class Solution {
public:
    int helper(string s, int k)
    {
        int n = s.length();
        int r = 0, l = 0, cnt = 0;
        vector<int> freq(3, 0);
        
        while(r < n)
        {
            freq[s[r]-'a']++;
            int fCnt = 0;
            for(int i=0; i<3; i++) 
            {
                fCnt += (freq[i] > 0) ? 1 : 0;
            }
            while(fCnt > k)
            {
                freq[s[l]-'a']--;
                l++;

                fCnt = 0;
                for(int i=0; i<3; i++) 
                {
                    fCnt += (freq[i] > 0) ? 1 : 0;
                }
            }
            cnt += r - l + 1;
            r++;
        }

        return cnt;
    }

    int numberOfSubstrings(string s) 
    {
        int lessThan3 = helper(s, 3);
        int lessThan2 = helper(s, 2);
        return lessThan3 - lessThan2;
    }
};

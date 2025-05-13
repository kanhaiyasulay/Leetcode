class Solution {
public:
    int mod = 1e9 + 7;

    int lengthAfterTransformations(string s, int t) 
    {
        vector<int> freq(26, 0);
        for(auto ch:s )
            freq[ch-'a']++;
        
        while(t--)
        {
            vector<int> temp(26, 0);
            for(int i=0; i<26; i++)
            {
                char ch = i + 'a';
                if(ch != 'z')
                {
                    temp[(ch+1)-'a'] = (temp[(ch+1)-'a'] + freq[i]) % mod;
                }else
                {
                    temp[0] = (temp[0] + freq[ch-'a']) % mod; // i.e 'a'
                    temp[1] = (temp[1] + freq[ch-'a']) % mod; // i.e 'b'
                }
            }
            freq = temp;
        }
        int cnt = 0;
        for(int i=0; i<26; i++)
            cnt = (cnt+freq[i]) % mod;
        
        return cnt;
    }
};
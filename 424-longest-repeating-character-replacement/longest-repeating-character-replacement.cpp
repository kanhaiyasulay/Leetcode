class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int n = s.length();
        int r = 0, l = 0, maxLen = 0, maxFreq = 0;
        vector<int> freq(26, 0);

        while(r < n)
        {
            freq[s[r] - 'A']++;
            maxFreq = max(maxFreq, freq[s[r]-'A']);

            while((r-l+1) - maxFreq > k)
            {
                freq[s[l]-'A']--;
                l++;

                maxFreq = 0;
                for(int i=0; i<26; i++) 
                    maxFreq = max(maxFreq, freq[i]);
            }
            maxLen = max(maxLen, (r-l+1));
            r++;
        }

        return maxLen;
    }
};
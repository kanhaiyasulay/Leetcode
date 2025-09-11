class Solution {
public:
    string sortVowels(string s) 
    {
        map<char, int> mp;
        mp['A'] = 0;
        mp['E'] = 0;
        mp['I'] = 0;
        mp['O'] = 0;
        mp['U'] = 0;
        mp['a'] = 0;
        mp['e'] = 0;
        mp['i'] = 0;
        mp['o'] = 0;
        mp['u'] = 0;

        for(auto it:s )
            if(mp.find(it) != mp.end()) mp[it]++;
        
        for(int i=0; i<s.length(); i++)
        {
            if(mp.find(s[i]) == mp.end()) continue;
            for(auto ch:mp )
            {
                if(ch.second > 0)
                {
                    s[i] = ch.first;
                    mp[ch.first]--;
                    break;
                }
            }
        }

        return s;
    }
};
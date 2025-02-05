class Solution {
public:
    bool areAlmostEqual(string s1, string s2) 
    {
        if(s1.length() != s2.length())     return false;

        int cnt = 0;

        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        for(auto ch:s1 ) mp1[ch]++;

        for(auto ch:s2 ) mp2[ch]++;

        for(auto ch:s1 )
            if(mp1[ch] != mp2[ch]) return false;

        for(int i=0; i<s1.length(); i++)
        {
            if(s1[i] != s2[i]) cnt++;
            if(cnt > 2) return false;
        }
        if(cnt == 0 || cnt == 2) return true;
        return false;
    }
};
class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        unordered_map<char, int> mp;
        for(auto ch:p ) mp[ch]++;

        unordered_map<char, int> track;

        int n = s.length();
        int l=0, r=0;
        vector<int> result;

        while(r < n)
        {
            track[s[r]]++;
            if(r-l+1 == p.length())
            {
                if(mp == track) result.push_back(l);
                track[s[l]]--;
                if(track[s[l]] == 0) track.erase(s[l]);
                l++;
            }

            r++;
        }

        return result;
    }
};
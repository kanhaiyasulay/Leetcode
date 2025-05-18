class Solution {
public:
    int partitionString(string str) 
    {
        unordered_map<char, int> mp;
        int s = 0, e = 0;
        int cnt = 1;

        while(e < str.length())
        {
            if(mp.find(str[e]) != mp.end() && mp[str[e]] >= s)
            {
                cnt++;
                s = e;
                mp[str[e]] = e;
            }
            else
            {
                mp[str[e]] = e;
            }
            e++;
        }

        return cnt;
    }
};
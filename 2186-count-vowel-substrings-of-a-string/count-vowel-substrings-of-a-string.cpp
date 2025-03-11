class Solution {
    bool isVowel(char ch)
    {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        return false;
    }
public:
    int countVowelSubstrings(string word) 
    {
        int l = 0, r = 0, cnt = 0, n = word.size();
        unordered_map<char, int> mp;

        while(r < n)
        {
            char ch = word[r];
            if(isVowel(ch)) mp[ch]++;
            else
            {
                l = r+1;
                mp.clear();
            }

            if(mp.size() == 5)
            {
                int idx = r;
                int validSubstr = 0;
                while(idx < n && isVowel(word[idx++])) validSubstr++;
                
                cnt += validSubstr;

                while(mp.size() == 5)
                {
                    mp[word[l]]--;
                    if(mp[word[l]] == 0) mp.erase(word[l]);
                    else
                        cnt += validSubstr;
                    l++;
                }

            }
            r++;
        }
        return cnt;
    }
};

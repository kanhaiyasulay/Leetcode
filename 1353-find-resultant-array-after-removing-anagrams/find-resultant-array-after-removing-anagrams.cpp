class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) 
    {
        int n = words.size();
        for(int i=0; i<n; i++)
        {
            if(words[i] == "1") continue;

            string curr = words[i];
            int hash1[26] = {0};
            for(auto it:curr ) hash1[it-'a']++;

            for(int j=i+1; j<n; j++)
            {
                if(words[j] == "1" || curr.length() != words[j].length()) break;

                int hash2[26] = {0};
                for(auto it:words[j]) hash2[it-'a']++;

                bool ok = true;
                for(int k=0; k<26; k++) if(hash1[k] != hash2[k]) ok = false;

                if(ok) words[j] = "1";
                else break;
            }
        }

        vector<string> ans;
        for(auto it:words ) if(it != "1") ans.push_back(it);

        return ans;
    }
};
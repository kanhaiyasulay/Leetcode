class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) 
    {
        vector<string> ans;
        for(int i=0; i<groups.size(); i++)
        {
            vector<int> temp;
            for(int j=i; j<groups.size(); j++)
            {
                if(temp.size() == 0) temp.push_back(j);
                else if(groups[j] == groups[temp.back()]) continue;
                else temp.push_back(j);
            }

            if(temp.size() > ans.size())
            {
                for(int k=0; k<temp.size(); k++)
                    ans.push_back(words[temp[k]]);
            }
            
        }

        return ans;
    }
};
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        sort(folder.begin(), folder.end());
        for(int i=0; i<folder.size(); i++)
        {
            string curr = folder[i];
            ans.push_back(curr);
            int cnt = 0;

            for(int j=i+1; j<folder.size(); j++)
            {
                string temp = folder[j];
                bool broken = false;
                int k=0;
                for(; k<curr.length(); k++)
                {
                    if(k == temp.length() || curr[k] != temp[k]) 
                    {
                        broken = true;
                        break;
                    }
                }
                if(k < temp.length() && temp[k] != '/')
                    broken = true;
                if(broken) 
                {
                    break;
                } else cnt++;
            }
            for(int f=0; f<cnt; f++) i++;
        }

        return ans;
    }
};
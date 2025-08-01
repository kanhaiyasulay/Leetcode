class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> ans;
        ans.push_back({1});
        for(int i=1; i<numRows; i++)
        {
            vector<int> temp;
            temp.push_back(1);
            vector<int> back = ans.back();
            for(int j=0; j<back.size(); j++)
            {
                if(j == back.size()-1) 
                {
                    temp.push_back(1);
                    break;
                }
                temp.push_back(back[j]+back[j+1]);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
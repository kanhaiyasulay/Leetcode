class Solution {
public:
    vector<int> lexicalOrder(int n) 
    {
        vector<string> srr;
        for(int i=1; i<=n; i++)
        {
            string temp = to_string(i);
            srr.push_back(temp);
        }
        sort(srr.begin(), srr.end());
        vector<int> ans;
        for(auto it:srr ) ans.push_back(stoi(it));

        return ans;
    }
};
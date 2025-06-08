class Solution {
public:
    vector<int> lexicalOrder(int n) 
    {
        set<string> srr;
        for(int i=1; i<=n; i++)
        {
            string temp = to_string(i);
            srr.insert(temp);
        }
        vector<int> ans;
        for(auto it:srr ) ans.push_back(stoi(it));

        return ans;
    }
};
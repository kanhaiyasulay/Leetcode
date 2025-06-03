class Solution {
public:
    void permut(int n, string& s, vector<string>& ans, string& temp, vector<bool>&vis)
    {
        if(temp.length() >= n)
        {
            ans.push_back(temp);
            return;
        }

        for(int i=0; i<n; i++)
        {
            if(vis[i]) continue;

            vis[i] = true;
            temp.push_back(s[i]);
            permut(n, s, ans, temp, vis);
            vis[i] = false;
            temp.pop_back();
        }
    }
    string getPermutation(int n, int k) 
    {
        string s = "";
        for(char ch='1'; ch<n+'1'; ch++) s += ch;
        vector<string> ans;
        string temp = "";
        vector<bool> vis(n, false);
        permut(n, s, ans, temp, vis);
        return ans[k-1];
    }
};
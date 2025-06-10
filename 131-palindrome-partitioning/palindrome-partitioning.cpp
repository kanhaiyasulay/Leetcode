class Solution {
    bool isPalindrome(string& str)
    {
        int s = 0, e = str.length()-1;
        while(s <= e)
            if(str[s++] != str[e--]) return false;
        return true;
    }
public:
    void backtrack(string& s, vector<vector<string>>& ans, vector<string>& temp, int idx)
    {
        if(idx >= s.length())
        {
            ans.push_back(temp);
            return;
        }

        for(int i=idx; i<s.length(); i++)
        {
            string str = s.substr(idx, i-idx+1);
            if(!isPalindrome(str)) continue;

            temp.push_back(str);
            backtrack(s, ans, temp, i+1);
            temp.pop_back();
        }
    }
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> ans;
        vector<string> temp;
        backtrack(s, ans, temp, 0);
        return ans;
    }
};
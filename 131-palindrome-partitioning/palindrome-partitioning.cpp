class Solution {
public:
    bool isPalindrome(string str)
    {
        int l = 0, r = str.length()-1;
        while(l < r)
        {
            if(str[l] != str[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void backtrack(vector<vector<string>>& ans, vector<string>& temp, string s, int idx)
    {
        if(idx == s.length()) 
        {
            ans.push_back(temp);
            return;
        }
        for(int i=idx; i<s.length(); i++)
        {
            string str = s.substr(idx, i-idx+1);
            if(!isPalindrome(str)) continue;
            temp.push_back(str);
            backtrack(ans, temp, s, i+1);
            temp.pop_back();
        }
    }
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> ans;
        vector<string> temp;

        backtrack(ans, temp, s, 0);
        return ans;
    }
};
class Solution {
    bool isPalindrome(string s)
    {
        int i = 0, j = s.length()-1;
        while(i < j)
        {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
public:
    void backtrack(string s, vector<string>& temp, vector<vector<string>>& ans, int idx)
    {
        if(idx == s.length()) 
        {
            ans.push_back(temp);
            return;
        }

        for(int i=idx; i<s.length(); i++)
        {
            string curr = s.substr(idx, i-idx+1);
            if(isPalindrome(curr))
            {
                temp.push_back(curr);
                backtrack(s, temp, ans, i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> ans;
        vector<string> temp;
        backtrack(s, temp, ans, 0);
        return ans;
    }
};
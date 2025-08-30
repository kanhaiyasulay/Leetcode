class Solution {
public:
    void allSubs(string& digits, unordered_map<char, vector<char>>& mp, vector<string>& ans, string& temp, int idx)
    {
        if(temp.length() == digits.length())
        {
            ans.push_back(temp);
            return;
        }

        for(int i=idx; i<digits.length(); i++)
        {
            for(auto ch:mp[digits[i]] ) 
            {
                temp.push_back(ch);
                allSubs(digits, mp, ans, temp, i+1);
                temp.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) 
    {
        unordered_map<char, vector<char>> mp;
        mp['2'] = {'a', 'b', 'c'};
        mp['3'] = {'d', 'e', 'f'};
        mp['4'] = {'g', 'h', 'i'};
        mp['5'] = {'j', 'k', 'l'};
        mp['6'] = {'m', 'n', 'o'};
        mp['7'] = {'p', 'q', 'r', 's'};
        mp['8'] = {'t', 'u', 'v'};
        mp['9'] = {'w', 'x', 'y', 'z'};

        vector<string> ans;
        string temp = "";
        allSubs(digits, mp, ans, temp, 0);
        if(ans.size() == 1 && ans.back() == "") return {};
        return ans;
    }
};
class Solution {
public:
    bool isDigit(char ch) {
        if(ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9') return true;
        return false;
    }
    
    string clearDigits(string s) 
    {
        string ans = "";
        for(int i=0; i<s.length(); i++)
        {
            if(isDigit(s[i]))
            {
                if(ans.length() > 0) ans.pop_back();
            }
            else
                ans.push_back(s[i]);
        }
        return ans;
    }
};
class Solution {
public:
    bool found = false;
    void backtrack(int n, string& temp, int idx, unordered_set<string>& st)
    {
        if(idx >= n)
        {
            if(st.find(temp) == st.end()) found = true;
            cout<<temp<<endl;
            return;
        }

        temp.push_back('1');
        backtrack(n, temp, idx+1, st);
        if(found) return;
        temp.pop_back();
    
        temp.push_back('0');
        backtrack(n, temp, idx+1, st);
        if(found) return;
        temp.pop_back();
    }
    string findDifferentBinaryString(vector<string>& nums) 
    {
        int n = nums[0].length();
        string temp = "";

        unordered_set<string> st;
        for(auto it:nums ) st.insert(it);
        st.insert("");

        backtrack(n, temp, 0, st);
        return temp;
    }
};
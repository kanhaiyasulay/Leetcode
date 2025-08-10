class Solution {
public:
    bool reorderedPowerOf2(int n) 
    {
        unordered_set<string> st;
        int num = 1;
        while(num <= 1e9)    
        {
            string s = to_string(num);
            sort(s.begin(), s.end());
            st.insert(s);
            num *= 2;
        }
        string s = to_string(n);
        sort(s.begin(), s.end());

        return st.find(s) != st.end();
    }
};
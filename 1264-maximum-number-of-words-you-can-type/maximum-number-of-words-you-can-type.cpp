class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) 
    {
        unordered_set<char> st;
        for(auto it:brokenLetters )
        {
            st.insert(it);
        }

        string temp = "";
        bool notFound = true;
        int cnt = 0;

        for(auto it:text )
        {
            temp += it;
            if(st.find(it) != st.end()) 
            {
                notFound = false;
            }
            if(it == ' ')
            {
                temp = "";
                cnt += notFound;
                notFound = true;
            }
        }
        cnt += notFound;

        return cnt;
    }
};
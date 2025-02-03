class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        unordered_set<string> st;
        for(auto a:wordList ) st.insert(a);

        while(!q.empty())
        {
            string temp = q.front().first;
            int step = q.front().second;
            q.pop();

            cout<<temp<<"   "<<step<<endl;
            if(temp == endWord) return step;

            for(int i=0; i<temp.length(); i++)
            {
                string check = temp;
                for(char ch='a'; ch<='z'; ch++)
                {
                    check[i] = ch;
                    if(st.find(check) != st.end())
                    {
                        q.push({check, step+1});
                        st.erase(check);
                    }
                }
            }
        }

        return 0;
    }
};
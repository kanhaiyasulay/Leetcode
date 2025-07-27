class Solution {
public:
    int MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) 
    {
        int n = arr.size();
        stack<pair<int,int>> st;
        vector<int> ans(n, 0);
        int cnt = 0;

        for(int i=n-1; i>=0; i--)
        {
            if(st.empty())
            {
                st.push({arr[i], i});
                cnt = (n-i)*arr[i];
                ans[i] = cnt;
            }
            else
            {
                while(!st.empty() && st.top().first > arr[i])
                    st.pop();
                
                if(st.empty())
                {
                    st.push({arr[i], i});
                    cnt = (n-i)*arr[i];
                    ans[i] = cnt;
                }
                else
                {
                    int idx = st.top().second;
                    cnt = (idx-i)*arr[i] + ans[idx];
                    st.push({arr[i], i});
                    ans[i] = cnt;
                }
            }
        }

        int result = 0;
        for(auto it:ans ) 
        {
            result += it;
            result %= MOD;
        }

        return result;
    }
};
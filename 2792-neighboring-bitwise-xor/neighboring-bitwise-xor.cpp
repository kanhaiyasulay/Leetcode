class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) 
    {
        int n = derived.size();
        if(n == 1 && derived[0] == 1) return false;
        if(n == 1 && derived[0] == 0) return true;
        vector<int> ans(n, -1);

        if(derived[n-1] == 0)
        {
            ans[0] = 1;
            ans[n-1] = 1;
        }
        else
        {
            ans[0] = 1;
            ans[n-1] = 0;
        }

       for(int i=n-2; i>0; i--)
       {
            if(derived[i] == 1)
            {
                ans[i] = ans[i+1] == 0 ? 1 : 0;
            }
            else 
            {
                ans[i] = ans[i+1];
            }
       }

       for(int i=0; i<n-1; i++)
       {
            int check = ans[i] ^ ans[i+1];
            if(derived[i] != check) return false;
       }

       return true;
    }
};
class Solution {
public:
    bool checkZeros(string str1, string str2)
    {
        for(auto it:str1 ) if(it == '0') return false;
        for(auto it:str2 ) if(it == '0') return false;
        return true;
    }
    vector<int> getNoZeroIntegers(int n) 
    {
        vector<int> ans(2, 0);
        int first = n-1;
        int second = 1;

        while(first >= second)
        {
            if(checkZeros(to_string(first), to_string(second)))
            {
                ans[0] = first;
                ans[1] = second;
                return ans;
            }
            first--;
            second++;
        }
        return ans;
    }
};
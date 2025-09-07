class Solution {
public:
    vector<int> sumZero(int n) 
    {
        int mid = n/2;
        vector<int> ans;
        while(mid > 0)
        {
            ans.push_back(mid);
            ans.push_back((mid*(-1)));
            mid--;
        }
        if(ans.size() != n) ans.push_back(0);
        return ans;
    }
};
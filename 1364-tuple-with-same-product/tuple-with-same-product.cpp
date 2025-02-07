class Solution {
public:
    int tupleSameProduct(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i == j) continue;
                mp[nums[i]*nums[j]]++;
            }
        }
        
        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i == j) continue;
                if(mp[nums[i]*nums[j]] > 2)
                {
                    cnt += mp[nums[i]*nums[j]] - 2;
                }
            }
        }

        return cnt;
    }
};
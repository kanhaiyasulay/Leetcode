class Solution {
public:
    int minimumIndex(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(auto it:nums ) mp[it]++;

        int maxi = 0;
        int maxiEle = -1;
        for(auto it:mp ) 
        {
            if(it.second > maxi)
            {
                maxi = it.second;
                maxiEle = it.first;
            }
        }

        int cnt = 0;
        int other = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i] == maxiEle) cnt++;
            else other++;
            if(cnt > other)
            {
                int right = n-i-1;
                int remainingMaxi = maxi - cnt;
                if(remainingMaxi > right/2) return i;
                return -1;
            }
        }

        return -1;
    }
};
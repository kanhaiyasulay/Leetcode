class Solution {
public:
    int countPairs(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int cnt = 0;

        unordered_map<int, vector<int>> mp;
        for(int i=0; i<n; i++)   mp[nums[i]].push_back(i);

        for(int i=0; i<n; i++)
        {
            for(auto it:mp[nums[i]])
            {
                if(it < i && (it*i)%k == 0) cnt++;
            }
        }

        return cnt;
    }
};
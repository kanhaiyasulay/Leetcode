class Solution {
    int findKDist(vector<int>& nums, int k)
    {
        int n = nums.size();
        int r=0, l=0, cnt=0;
        unordered_map<int, int> mp;

        while(r < n)
        {
            mp[nums[r]]++;
            while(mp.size() > k && l <= r)
            {
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
            cnt += r-l+1;
            r++;
        }
        return cnt;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        int subarrayWithLessThanOrEqualKDistinct = findKDist(nums, k);
        int subarrayWithLessThanKDistinct = findKDist(nums, k-1);

        return subarrayWithLessThanOrEqualKDistinct - subarrayWithLessThanKDistinct;
    }
};
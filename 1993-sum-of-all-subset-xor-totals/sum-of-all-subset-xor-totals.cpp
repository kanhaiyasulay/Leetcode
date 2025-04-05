class Solution {
    void inclusionExclusion(vector<int>& nums, vector<vector<int>>& subsets, vector<int>& temp, int idx)
    {
        if(idx >= nums.size())
        {
            subsets.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        inclusionExclusion(nums, subsets, temp, idx+1);
        temp.pop_back();

        inclusionExclusion(nums, subsets, temp, idx+1);
    }
public:
    int subsetXORSum(vector<int>& nums) 
    {
        vector<vector<int>> subsets;
        vector<int> temp;
        inclusionExclusion(nums, subsets, temp, 0);

        int ans = 0;
        for(auto it:subsets )
        {
            int sum = 0;
            for(auto a:it ) sum ^= a;
            ans += sum;
        }
        
        return ans;
    }
};
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) 
    {
        int n = nums.size();
        for(int i=0; i<n-1; i++)    
        {
            if(nums[i] == nums[i+1])
            {
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }

        vector<int> ans;
        int cntZeros = 0;
        for(auto& a:nums )
        {
            if(a == 0) cntZeros++;
            else ans.push_back(a);
        }

        while(cntZeros--) ans.push_back(0);

        return ans;
    }
};
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        int max_count = 1;
        for(int i=0; i<nums.size(); i++) {
            int count = 1;
            for(int j=i; j<nums.size()-1; j++) {
                if(nums[j] <= nums[j+1]) break;
                else count++;
            }
            max_count = max(max_count, count);
        }
        for(int i=0; i<nums.size(); i++) {
            int count = 1;
            for(int j=i; j<nums.size()-1; j++) {
                if(nums[j] >= nums[j+1]) break;
                else count++;
            }
            max_count = max(max_count, count);
        }
        return max_count;
    }
};
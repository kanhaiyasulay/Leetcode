class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) 
    {
        long long cnt = 0;
        int i=0, j=0;
        int n = nums.size();

        while(j < n)   
        {
            while(j < n && nums[j] == 0) j++;
            long long len = j-i;
            if(len >= 1) cnt += len*(len+1)/2;
            j++;
            i = j;
        }

        return cnt;
    }
};
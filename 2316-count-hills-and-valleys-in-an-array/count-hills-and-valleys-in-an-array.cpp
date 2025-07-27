class Solution {
public:
    int countHillValley(vector<int>& nums) 
    {
        int cnt = 0, n = nums.size();
        for(int i=0; i<n; i++)
        {
            int left = i, right = i;
            while(left >= 0 && nums[left] == nums[i]) 
                left--;
            while(right < n && nums[right] == nums[i])
                right++;
            
            if(left < 0 || right >= n || left == i || right == i) continue;
            if(nums[left] < nums[i] && nums[right] < nums[i]) cnt++;
            else if(nums[left] > nums[i] && nums[right] > nums[i]) cnt++;

            i = right-1;
        }

        return cnt;
    }
};
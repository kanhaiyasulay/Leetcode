class Solution {
public:
    int largestPerimeter(vector<int>& nums) 
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int peri = 0;

        for(int i=2; i<n; i++)
        {
            int side1 = nums[i-2];
            int side2 = nums[i-1];

            if(side1 + side2 > nums[i]) peri = side1 + side2 + nums[i];
        }
        return peri;
    }
};
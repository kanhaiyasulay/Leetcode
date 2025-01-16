class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) 
    {
        int nums3 = 0;
        int num1 = 0;
        for(auto a:nums2 ) nums3 ^= a;
        for(auto a:nums1 ) num1 ^= a;

        int n1 = nums1.size(), n2 = nums2.size();
        if(n1%2 == 0 && n2%2 == 0) return 0;
        else if(n1%2 == 1 && n2%2 == 0) return nums3;
        else if(n1%2 == 1 && n2%2 == 1) return nums3 ^ num1;
        else
            return num1;
        return 0;
    }
};
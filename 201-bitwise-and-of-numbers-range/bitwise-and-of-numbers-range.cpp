class Solution {
public:
    int rangeBitwiseAnd(int left, int right) 
    {
        int shiftCnt = 0;

        while(left != right)    
        {
            left >>= 1;
            right >>= 1;
            shiftCnt++;
        }

        int ans = left;
        while(shiftCnt--) ans <<= 1;

        return ans;
    }
};
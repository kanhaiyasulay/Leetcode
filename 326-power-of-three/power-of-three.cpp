class Solution {
public:
    bool isPowerOfThree(int n) 
    {
        if(n <= 0) return false;
        if(n == 1) return true;
        if(n == 2) return false;
        long long val = 3;
        int i = 1;
        while( val < INT_MAX)
        {
            if(val == n) return true;
            val *= 3;
        }
        return false;
    }
};
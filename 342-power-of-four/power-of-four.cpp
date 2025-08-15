class Solution {
public:
    bool isPowerOfFour(int n) 
    {
        if(n <= 0) return false;
        long long prod = 1;
        while(prod <= n)
        {
            if(prod == n) return true;
            prod *= 4;
        }

        return false;
    }
};
class Solution {
public:
    int generateFreqNum(int n)
    {
        int num = 0;
        while(n > 0)
        {
            int digit = n%10;
            num += pow(10, digit);
            n /= 10;
        }
        return num;
    }
    bool reorderedPowerOf2(int n) 
    {
        int freqNum = generateFreqNum(n);
        for(int p=0; p<=29; p++)
        {
            int num = 1 << p;
            int check = generateFreqNum(num);
            if(check == freqNum) return true;
        }
        
        return false;
    }
};
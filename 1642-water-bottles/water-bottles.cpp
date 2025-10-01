class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) 
    {
        int cnt = numBottles;
        int newBottles = numBottles/numExchange;
        int extra = numBottles%numExchange;
        while(newBottles > 0)    
        {
            cnt += newBottles;
            newBottles += extra;
            extra = 0;
            extra = newBottles%numExchange;
            newBottles = newBottles/numExchange;
        }
        return cnt;
    }
};
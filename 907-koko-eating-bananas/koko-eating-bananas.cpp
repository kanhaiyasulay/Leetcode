class Solution {
    long long reqTime(vector<int>& piles, int num)
    {
        long long time = 0;
        for(auto a:piles )
            time += (a%num) ? (a/num) + 1 : a/num;
        return time;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int maxi = piles[0];
        for(auto a:piles ) maxi = max(maxi, a);

        int n = piles.size(), ans = -1;
        int s = 1, e = maxi, mid = s + (e - s) / 2;

        while(s <= e)
        {
            mid = s + (e - s) / 2;
            long long time = reqTime(piles, mid);

            if(time > h) 
            {
                s = mid+1;
            }
            else
            {
                ans = mid;
                e = mid-1;
            }
        }

        return ans;
    }
};
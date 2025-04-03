class Solution {
    int possible(vector<int>& weights, int k)
    {
        int cnt = 0, days = 0, n = weights.size();
        for(int i=0; i<n; i++)
        {
            if(cnt + weights[i] <= k) cnt += weights[i];
            else
            {
                cnt = weights[i];
                days++;
            }
        }
        days++;
        return days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int sum = 0;
        int maxi = 0;
        for(auto weight:weights ) 
        {
            sum += weight;
            maxi = max(maxi, weight);
        }

        int s = maxi, e = sum, mid = (s+e)/2, ans = 0;

        while(s <= e)
        {
            mid = (s+e)/2;

            int temp = possible(weights, mid);
            if(temp > days) s = mid+1;
            else 
            {
                ans = mid;
                e = mid-1;
            }
        }

        return ans;
    }
};
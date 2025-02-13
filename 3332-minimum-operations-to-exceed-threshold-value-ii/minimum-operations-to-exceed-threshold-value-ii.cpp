#define ll long long
class Solution {
public:
    int minOperations(vector<int>& nums, int k) 
    {
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] < k) pq.push(nums[i]);
        }

        if(pq.size() < 2) return pq.size();

        int cnt = 0;
        while(!pq.empty())
        {
            if(pq.top() >= k) break;
            if(pq.size() == 1) return cnt + 1;
            ll m1 = pq.top();
            pq.pop();
            ll m2 = pq.top();
            pq.pop();

            ll newM = min(m1, m2) * 2 + max(m1, m2);
            pq.push(newM);
            cnt++;
        }

        return cnt;
    }
};
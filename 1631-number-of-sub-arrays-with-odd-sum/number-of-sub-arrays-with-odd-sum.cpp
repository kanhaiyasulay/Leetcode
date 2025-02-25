class Solution {
public:
    int mod = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) 
    {
        int sum = 0, cnt = 0, n = arr.size();
        int oddCnt = 0;
        int evenCnt = 1;

        for(int i=0; i<n; i++)
        {
            sum += arr[i];

            if(sum%2)
            {
                cnt += evenCnt;
                oddCnt++;
            }
            else
            {
                cnt += oddCnt;
                evenCnt++;
            }
            cnt %= mod;
        }

        return cnt;
    }
};
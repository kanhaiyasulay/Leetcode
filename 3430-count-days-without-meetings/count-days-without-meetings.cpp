class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) 
    {
        int n = meetings.size();
        sort(meetings.begin(), meetings.end());

        int endDay = 0;
        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            if(meetings[i][0] > endDay)
            {
                cnt += meetings[i][0] - endDay - 1;
            }
            if(meetings[i][1] > endDay)
            {
                endDay = meetings[i][1];
            }
        }
        if(days > endDay)
        {
            cnt += days - endDay;
        }

        return cnt;
    }
};
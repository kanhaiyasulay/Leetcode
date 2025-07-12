class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) 
    {
        int n = endTime.size();
        vector<int> freeTime;

        freeTime.push_back(startTime[0]);  // before the first meeting
        for (int i = 0; i < n - 1; i++) {
            freeTime.push_back(startTime[i + 1] - endTime[i]);  // between meetings
        }
        freeTime.push_back(eventTime - endTime.back());  // after last meeting

        int m = freeTime.size();
        vector<int> leftMax(m, 0), rightMax(m, 0);

        for (int i = 1; i < m; i++) {
            leftMax[i] = max(leftMax[i - 1], freeTime[i - 1]);
        }
        for (int i = m - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], freeTime[i + 1]);
        }

        int maxi = 0;
        for (int i = 1; i <= n; i++) {
            int currMeeting = endTime[i-1] - startTime[i - 1];

            int left = freeTime[i - 1];
            int right = freeTime[i];

            // Case I: Completely remove the meeting
            if (currMeeting <= max(leftMax[i - 1], rightMax[i])) {
                maxi = max(maxi, left + right + currMeeting);
            }

            // Case II: Just slide meeting to one side
            maxi = max(maxi, left + right);
        }

        return maxi;
    }
};

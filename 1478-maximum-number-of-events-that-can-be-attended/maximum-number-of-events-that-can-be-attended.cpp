class Solution {
public:
    int maxEvents(vector<vector<int>>& events) 
    {
        int n = events.size();

        sort(events.begin(), events.end());

        priority_queue<int, vector<int>, greater<int>> pq; 
        int day   = events[0][0]; 
        int i     = 0;
        int count = 0; 

        while(!pq.empty() || i < n) 
        {    
            // skip those days when there are no events
            if(pq.empty()) 
                day = events[i][0];

            while(i < n && events[i][0] == day) 
            {
                pq.push(events[i][1]);
                i++;
            }

            if(!pq.empty()) 
            {
                pq.pop(); //1 event attended on this day
                count++; //counting the result
            }

            day++;

            //skip those events whose endDay < day
            while(!pq.empty() && pq.top() < day)
            {
                pq.pop();
            }
        }

        return count;
    }
};
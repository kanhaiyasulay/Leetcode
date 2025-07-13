class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) 
    {
        priority_queue<int, vector<int>, greater<int>> playerPq;
        priority_queue<int, vector<int>, greater<int>> trainerPq;

        for(auto it:players ) playerPq.push(it);
        for(auto it:trainers ) trainerPq.push(it);

        int cnt = 0;

        while(!playerPq.empty() && !trainerPq.empty())
        {
            int currPlayer = playerPq.top();

            while(currPlayer > trainerPq.top())
            {
                trainerPq.pop();
                if(trainerPq.empty()) return cnt;
            }
            cnt++;
            playerPq.pop();
            trainerPq.pop();
        }

        return cnt;
    }
};
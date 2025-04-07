class Solution {
public:
    vector<int> sequentialDigits(int low, int high) 
    {
        vector<int> ans;

        queue<int> q;
        for(int i=1; i<9; i++) q.push(i);

        while(!q.empty())
        {
            int front = q.front();
            if(front >= low) ans.push_back(front);
            q.pop();
            int lastEle = front%10;
            if(lastEle >= 9) continue;
            int nextEle = lastEle + 1;
            int updated = (front*10) + nextEle;
            if(updated <= high) q.push(updated);

        }

        return ans;
    }
};
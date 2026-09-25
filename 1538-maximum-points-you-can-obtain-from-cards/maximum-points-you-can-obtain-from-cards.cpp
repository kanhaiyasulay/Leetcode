class Solution {
public:
    int sw(vector<int>& cardPoints, int size, int totalSum)
    {
        int r = 0, l = 0;
        int sum = 0, minSum = INT_MAX;

        while(r < cardPoints.size())
        {
            sum += cardPoints[r];

            while(r-l+1 > size)
            {
                sum -= cardPoints[l++];
            }

            if(r-l+1 == size) minSum = min(minSum, sum);
            r++;
        }

        return totalSum - minSum;
    }
    int maxScore(vector<int>& cardPoints, int k) 
    {
        int totalSum = 0;
        for(auto it:cardPoints ) totalSum += it;
        int size = cardPoints.size() - k;
        if(size == 0) return totalSum;

        return sw(cardPoints, size, totalSum);
    }
};
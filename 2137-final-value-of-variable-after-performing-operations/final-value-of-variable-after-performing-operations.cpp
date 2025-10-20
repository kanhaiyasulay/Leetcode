class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) 
    {
        int val = 0;
        for(auto it:operations )
        {
            if(it == "--X") --val;
            else if(it == "X++") val++;
            else if(it == "++X") ++val;
            else val--;
        }

        return val;
    }
};
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) 
    {
        vector<int> ans;
        int cntPivot = 0;
        for(auto it:nums )
        {
            if(it < pivot) ans.push_back(it);
            if(it == pivot) cntPivot++;
        }

        while(cntPivot--) ans.push_back(pivot);

        for(auto it:nums )
        {
            if(it > pivot) ans.push_back(it);
        }

        return ans;
    }
};
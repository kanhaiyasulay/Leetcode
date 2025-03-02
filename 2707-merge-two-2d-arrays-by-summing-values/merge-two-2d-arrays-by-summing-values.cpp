class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) 
    {
        int i = 0, j = 0;
        int n1 = nums1.size(), n2 = nums2.size();

        vector<vector<int>> ans;
        while(i < n1 && j < n2)
        {
            int i1 = nums1[i][0];
            int j1 = nums2[j][0];

            if(i1 < j1)
            {
                ans.push_back(nums1[i]);
                i++;
            }
            else if(j1 < i1)
            {
                ans.push_back(nums2[j]);
                j++;
            }
            else
            {
                vector<int> temp;
                temp.push_back(i1);
                temp.push_back(nums1[i][1] + nums2[j][1]);

                ans.push_back(temp);
                i++; j++;
            }
        }
        while(i < n1)
        {
            ans.push_back(nums1[i]);
            i++;
        }
        while(j < n2)
        {
            ans.push_back(nums2[j]);
            j++;
        }

        return ans;
    }
};
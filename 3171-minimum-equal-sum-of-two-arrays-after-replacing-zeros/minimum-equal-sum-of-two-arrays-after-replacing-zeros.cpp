#define ll long long
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) 
    {
        ll sum1 = 0, sum2 = 0;
        ll zeros1 = 0, zeros2 = 0;
        for(auto it:nums1 ) 
        {
            sum1 += it;
            if(it == 0) zeros1++;
        }
        for(auto it:nums2 ) 
        {
            sum2 += it;
            if(it == 0) zeros2++;
        }
        cout<<sum1<<" -> "<<zeros1<<endl;
        cout<<sum2<<" -> "<<zeros2<<endl;

        if(sum1+zeros1 == sum2+zeros2) return sum1+zeros1;
        if(sum1 == sum2 && (zeros1==0 && zeros2 == 0)) return sum1;
        if(sum1 == sum2 && (zeros1==0 || zeros2==0)) return -1;

        if(sum2+zeros2 > sum1+zeros1)
        {
            if(zeros1 == 0) return -1;
            return sum2+zeros2;
        }else
        {
            if(zeros2 == 0) return -1;
            return sum1+zeros1;
        }

        return -1;
    }
};
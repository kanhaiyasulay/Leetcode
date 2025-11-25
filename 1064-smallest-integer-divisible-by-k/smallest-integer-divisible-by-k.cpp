class Solution {
public:
    int smallestRepunitDivByK(int k) 
    {
        unordered_set<int> st;

        int len = 1;
        int num = 1;

        while(true)   
        {
            num = num%k;

            if(num == 0)
                return len;
            
            if(st.find(num) != st.end()) return -1;
            st.insert(num);

            len++;
            num *= 10;
            num += 1;
        }

        return -1;
    }
};
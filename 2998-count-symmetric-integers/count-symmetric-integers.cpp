class Solution {
    int secondHalf(string& s)
    {
        int sum = 0, len = s.length();
        for(int i=len-1; i>=len/2; i--) sum += s[i]-'0';
        return sum;
    }
    int firstHalf(string& s)
    {
        int sum = 0, len = s.length()/2;
        for(int i=0; i<len; i++) sum += s[i]-'0';
        return sum;
    }
public:
    int countSymmetricIntegers(int low, int high) 
    {
        int cnt = 0;
        int i = low;
        while(i <= high)
        {
            string s = to_string(i);
            if(s.length()%2 == 0)
            {
                int num1 = firstHalf(s);
                int num2 = secondHalf(s);
                if(num1 == num2) cnt++;
            }
            i++;
        }

        return cnt;
    }
};
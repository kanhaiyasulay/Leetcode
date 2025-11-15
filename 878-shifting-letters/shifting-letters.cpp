class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) 
    {
        int n = shifts.size();
        vector<int> arr(n, 0);

        long long runSum = 0;
        for(int i=n-1; i>=0; i--)
        {
            runSum += (shifts[i]%26);
            arr[i] = runSum;
        }

        for(int i=0; i<n; i++)
        {
            int val = ((s[i]-'a') + arr[i])%26;
            s[i] = 'a' + val;
        }

        return s;
    }
};
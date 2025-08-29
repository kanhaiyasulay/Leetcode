class Solution {
public:
    long long flowerGame(int n, int m) 
    {
        long long oddInN = (n%2) == 0 ? n/2 : (n/2)+1;
        long long evenInM = m/2;

        long long first = oddInN * evenInM;

        long long oddInM = (m%2) == 0 ? m/2 : (m/2)+1;
        long long evenInN = n/2;

        long long second = oddInM * evenInN;
        return first+second;
    }
};
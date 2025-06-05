class Solution {
public:
    long long distributeCandies(int n, int limit) 
    {
        long long ways = 0;
        for(int child1=0; child1<=min(n, limit); child1++)
        {
            int N = n - child1;
            int child3 = N > limit ? limit : N;
            int child2 = N - child3;

            if(child2 <= limit && (child1 + child2 + child3 == n)) ways += child3 - child2 + 1;
        }
        return ways;
    }
};
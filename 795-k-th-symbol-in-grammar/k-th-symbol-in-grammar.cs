public class Solution {
    public int KthGrammar(int n, int k) {
        if(n == 1) return 0;
        if(n == 2)
        {
            if(k==1) return 0;
            if(k==2) return 1;
        }

        var l = (k-1)/2 + 1;
        var m = (k-1)%2;
        var ret =  KthGrammar(n-1, l);
        if(ret == 0)
        {
            if(m == 0) return 0;
            return 1;
        }
        else
        {
            if(m == 0) return 1;
            return 0;
        }
    }
    
}
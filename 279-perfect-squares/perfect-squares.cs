public class Solution {
    public int NumSquares(int n) 
    {
        int h = (int)Math.Sqrt(n);
        Queue<int> queue = new();
        queue.Enqueue(n);
        
        int steps = 0;
        
        while (queue.Count > 0)
        {
            int qSize = queue.Count;
            steps++;
            for (int i = 0; i < qSize; i++)
            {
                int num = queue.Dequeue();
                for (int p = h; p > 0; p--)
                {
                    int rem = num - p * p;
                    if (rem == 0)
                    {
                        return steps;
                    }
                    if (rem > 0)
                    {
                        queue.Enqueue(rem);
                    }
                }
            }
        }
        
        return steps;
    }
    
}
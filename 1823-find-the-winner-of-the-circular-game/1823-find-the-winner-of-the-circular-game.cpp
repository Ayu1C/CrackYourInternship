class Solution {
public:
    int findTheWinner(int n, int k) {
        
         queue<int> q;
         for(int i=1; i<=n; i++)
         {
             q.push(i);
         }
          
        while(n > 1)
        {
            for(int i=1; i<k; i++)
            {
                q.push(q.front());
                q.pop();
            }
            q.pop();
            n--;
        }
        
        return q.front();
        
    }
};
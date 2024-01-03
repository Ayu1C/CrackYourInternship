//f(n) = f(n-delay) + f(n-(delay+1)) +f(n-(delay+2)) ....f(n-(forget-1)) where n-i >=0. What this means is that each person tells the secret to forget-delay-1 people and they would do the same and so on.

static int MOD=1e9+7;
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        
        vector<long> memo(n+1,1);    // Each day contributes at least to 1 person kowing the secret.
        memo[0]=0;  // End case
        for(int i=1;i<=n;i++)
        {
            for(int j=i+delay;j<i+forget;j++)
            {
                // Number of people that the secret will be forwarded to
                if(j<=n)
                    memo[j]=(memo[j]+memo[i])%MOD;    // Same as our recursion relation.
                //i-j means ki at ith day, ek person ko to share hua he, this is person A who knew already, hum usme add karenge ki aj se delay din pehle jin logo ko pta tha, wo aaj share kar sakte, aur uske pehle ke din ke bhi sab log jinne share kiya, lekin agr 4 din pehle koi bhul gya ho to hum 4 din pehle ka count nhi karenge Read recurrence relation at top for more info.
             }
        }
            
        
        return (memo[n]-memo[n-forget]+MOD)%MOD;  // Subtract the people who found out by the `n-forget` day as observed.
        
    }
};
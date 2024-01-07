class Solution {
public:
    string getHint(string secret, string guess) {
        
        int n = secret.length(), bulls = 0, cows = 0;
        vector<int> mapped(n,0);
        
        for(int i=0; i<n; i++)
        {
            if(secret[i]==guess[i])
            {
                bulls++;
                mapped[i] = 1;
            }
            else
            {
                for(int j=0; j<n; j++)
                {   
                    if(guess[j]==secret[i] && mapped[j]==0)
                    {
                        if(j>i && guess[j]==secret[j]) continue; 
                        cows++;
                        mapped[j] = 1;
                        break;
                    }
                }
            }
        }
        
       return to_string(bulls)+'A'+to_string(cows)+'B';
    }
};
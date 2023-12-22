class Solution {
public:
    int maxScore(string s) {
        
        int n = s.length();
        int maxi = INT_MIN;
        
        vector<int> zeroes(n, 0);
        vector<int> ones(n, 0);
        
        s[0] == '0' ? zeroes[0]++ : ones[0]++;
        
        for(int i=1; i<n; i++)
        {
            if(s[i] == '0')
            {
                zeroes[i] = zeroes[i-1]+1;
                ones[i] = ones[i-1];
            }
            else{
                ones[i] = ones[i-1]+1;
                zeroes[i] = zeroes[i-1];
            }
        }
        
        for(int i=0; i<n-1; i++)
        {
            int score = zeroes[i] + (ones[n-1] - ones[i]);
            maxi = max(maxi, score);
        }
        
        return maxi;
         
    }
};
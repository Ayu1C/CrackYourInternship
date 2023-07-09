class Solution {
public:
    
    
    int kthFactor(int n, int k) {
        
        vector<int> factors;
        
        for(int i=1; i<n;  i++)
        {
           if(n%i == 0)factors.push_back(i);  
        }
        
        factors.push_back(n);
        
        if(k<=factors.size()) return(factors[k-1]);
        else return -1;
    }
};
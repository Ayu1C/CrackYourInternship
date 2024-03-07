class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int c = 0, m = flowerbed.size();
        
        if(m==1)
        {
            if((flowerbed[0]==0 && n<=1) || (flowerbed[0]==1 && n==0)) return true;
            else return false;
        }
        
        for(int i=0; i<m; i++)
        {
            if(flowerbed[i] == 1) continue;
            
            if(i==0) 
            {
                if(flowerbed[i+1]==0)
                {
                   flowerbed[i] = 1;
                    c++;
                }
            }
            else if(i==m-1)
            {
                if(flowerbed[m-2]==0)
                {
                    flowerbed[m-1] = 1;
                    c++;
                }
            }
            else 
            {
                if(flowerbed[i-1]==0 && flowerbed[i+1]==0)
                {
                    flowerbed[i] = 1;
                    c++;
                }
            }
        }
        
        return c>=n;
    }
};
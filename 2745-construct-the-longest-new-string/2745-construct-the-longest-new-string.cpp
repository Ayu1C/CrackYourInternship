class Solution {
public:
    int longestString(int x, int y, int z) {
        
        if(x==y) return 4*x+2*z;
        
        //else if(x>y) return (min(x,y)*2+2+2*z);
        
        else return (min(x,y)*4+2+2*z);
    }
};
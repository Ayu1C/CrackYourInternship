class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        
        int ax = abs(ax2 - ax1);
        int ay = abs(ay2 - ay1);
        int bx = abs(bx2 - bx1);
        int by = abs(by2 - by1);
        
        int totalArea = ax*ay + bx*by;
        int comX = 0, comY = 0;
        
        int cxL = max(ax1, bx1);
        int cxR = min(ax2, bx2);
        if(cxR>cxL) comX = abs(cxR - cxL);
        
        int cyB = max(ay1, by1);
        int cyT = min(ay2, by2);
        if(cyT>cyB) comY = abs(cyT - cyB);
        
        
        int area = totalArea - (comX * comY);
        
        return area;
        
    }
};
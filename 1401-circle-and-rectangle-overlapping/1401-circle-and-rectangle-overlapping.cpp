class Solution {
    
    //https://leetcode.com/problems/circle-and-rectangle-overlapping/discuss/563341/4-lines-C%2B%2B-O(1)%3A-Test-shortest-distance-from-center-to-rect-(with-pics)
    
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        //finding the closest coordinates to circle, by finding closest edges.
        int edgeX = (x_center < x1) ? x1 : (x_center > x2) ? x2 : x_center;
        int edgeY = (y_center < y1) ? y1 : (y_center > y2) ? y2 : y_center;
        
        //finding the distance between that edge and center of circle
        int distX = x_center - edgeX, distY = y_center - edgeY;
        
        //using pythagoras theorem here, if (hypo)^2 >= (perp)^2 + (base)^2; then hypo is greatest side; 
        return distX * distX + distY * distY <= radius * radius;
    }
};
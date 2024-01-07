class Solution {
    
private:
    map<int, int> mp;
    vector<vector<int>> rects;
    int sum; // sum denotes sum of areas of all rectangles, that means no.of points within rect = area of rect;
public:
    Solution(vector<vector<int>> rects) {
        this->rects = rects;
        int i = 0;
        sum = 0;
        for(vector<int> r : rects) {
            sum += (r[2]-r[0]+1) * (r[3]-r[1]+1); // finding len and width and multiply to get area of rect
            mp[sum] = i++; //mapping ith index rect with its area.
        }
    }
    
    vector<int> pick() {
        
        //upper bound dekhta he, generated area agar mp me nhi he to next greater area jo present he, wo pick karo
        map<int, int>::iterator iter = mp.upper_bound(rand()%(sum+1)); //generates an int in range[1, sum]
        vector<int> rect = rects[iter->second]; //find the idx of rect corr. to chosen area;
        int left = rect[0], right = rect[2], down = rect[1], up = rect[3];
        return {left + rand()%(right - left +1), down + rand()%(up - down + 1)}; 
        //lower x & y coordinate leke unme add karrhe [0,length] value to get next x or y
    }

};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
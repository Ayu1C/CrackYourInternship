class Solution {
    
 private:  
    int row = 0, col = 0, size = 0;
    unordered_set<int> v;
    
public:
    Solution(int m, int n) {
        row = m;
        col = n;
        size = m*n;
    }
    
    vector<int> flip() {
        
        if(v.size()==size) return {};
        
        int ran = rand() % size;
        while(v.count(ran))
        {
           ran = ++ran % size;
        }
        v.insert(ran);
        return {ran/col, ran%col};
    }
    
    void reset() {
        v = {};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
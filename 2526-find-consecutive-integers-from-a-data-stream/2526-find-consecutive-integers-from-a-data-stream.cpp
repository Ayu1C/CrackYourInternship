class DataStream {
    
    int dsValue, dsK;
    map<int, int> mp;
    queue<int> q;
    
public:
    DataStream(int value, int k) {
        
        //declaring a map to store number of ele having value equal to "value"
        dsValue = value;
        dsK = k;
        mp[dsValue] = 0;
    }
    
    bool consec(int num) {
        
        //push ele to queue, and update count in map if it is equal to value
        q.push(num);
        if(num == dsValue) mp[dsValue]++;
        
        bool ans = false;
        
        //if size of queue is less than k, return false
        if(q.size() < dsK) return false;
        
        //if size of q == k, then we will check whether we have k num of value count in map or not, if yes, then return true, else return false.
        
        else if(q.size()==dsK)
        {
            if(mp[dsValue]==dsK) ans = true;
            
            //we will remove front ele from queue, so that on next call of consec, size of q again becomes equal to k, and we will reduce count of value, if removed element is equal to value.
            
            if(q.front()==dsValue) mp[dsValue]--;
            q.pop();
            
        }
        
        return ans;
    }    
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
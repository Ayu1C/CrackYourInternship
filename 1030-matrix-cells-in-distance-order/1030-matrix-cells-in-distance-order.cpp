struct Compare {
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        return a[0] > b[0];  // Compare based on the 0th index element
    }
};

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
      
        priority_queue <vector<int>, vector<vector<int>>, Compare > pq; 
        
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                //if(i==rCenter && j==cCenter) continue;
                
                vector<int> temp;
                temp.push_back(abs(i-rCenter) + abs(j-cCenter));
                temp.push_back(i);
                temp.push_back(j);
                
                pq.push(temp);
            }
        }
        
        vector<vector<int>> ans;
        
        while(!pq.empty())
        {
            vector<int> temp = pq.top();
            pq.pop();
            ans.push_back({temp[1], temp[2]});
        }
        
        return ans;
    }
};
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        
        map<int, string> mp;
        
        for(int i=0; i<names.size(); i++){
            
            mp[heights[i]] = names[i];
        }
        
        vector<string> sorted_names;
        
        for(auto &it : mp){
            sorted_names.insert(sorted_names.begin(), it.second);
        }
        
        return sorted_names;
    }
};
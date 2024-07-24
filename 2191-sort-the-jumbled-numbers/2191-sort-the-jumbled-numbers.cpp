class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        multimap<int, int> corr;
        
        for(int i=0; i<nums.size(); i++) {
            
           int num = nums[i], new_num = 0, tens = 1;
            
           if(num == 0) {
              corr.insert(pair<int, int>(mapping[num], nums[i])); 
               continue;
           } 
            
           while(num){
                
               int rem = num % 10;
               rem = mapping[rem];
               new_num = rem*tens + new_num;
               tens *= 10;
               
               num /= 10;
           }
            
            corr.insert(pair<int, int>(new_num, nums[i]));
            
        }
    
        vector<int> ans;
        for(auto &it : corr) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        
        vector<int> ans;
        
        int q = queries.size(), n = nums.size(), n0 = nums[0].size();
        
        for(int qr = 0; qr < q; qr++)
        {
            vector<string> temp;
            int len = queries[qr][1], k = queries[qr][0];
            
            for(int i=0; i<n; i++)
            {
                temp.push_back(nums[i].substr(n0-len, len));
            }
            sort(temp.begin(), temp.end());
            
            string ksmallest = temp[k-1];
            int strIdx = -1, endIdx = -1;
            
            if((k-2>=0 && temp[k-1]==temp[k-2]) || (k<n && temp[k-1]==temp[k]))
            {
                for(int p=0; p<n; p++)
                {
                    if(temp[p]==ksmallest)
                    {
                        strIdx = p;
                        for(int t=p; t<n; t++)
                        {
                            if(temp[t]==ksmallest)
                            {
                                endIdx = t;
                            } else
                                break;
                        }
                        break;
                    }
                }
            }
            
            int count = 1;
            
            for(int j=0; j<n; j++)
            {
                if(strIdx == -1){
                   if(nums[j].substr(n0-len, len) == ksmallest)
                   {
                       ans.push_back(j);
                       break;
                   } 
                }
                else{
                    if(nums[j].substr(n0-len, len) == ksmallest)
                    {
                       if(count == k - strIdx)
                       {
                           ans.push_back(j);
                           break;
                       }
                       else{
                           count++; 
                        }
                    } 
                    
                }
                
            }
        }
        
        return ans;
        
    }
};
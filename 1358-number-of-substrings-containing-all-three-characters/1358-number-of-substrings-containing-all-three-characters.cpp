class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int i = 0;
        int j = 0;
        int cnt = 0;
        unordered_map<int,int> mp;
        while(j < s.length()){
            mp[s[j]]++;
            if(mp.size() == 3){
                while(mp.size() == 3){
                    cnt += s.length()-j;
                    mp[s[i]]--;
                    if(mp[s[i]] == 0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
            }
            j++;
            
        }
        return cnt;
    }
};
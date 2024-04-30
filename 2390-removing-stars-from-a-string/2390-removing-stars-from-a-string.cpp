class Solution {
public:
    string removeStars(string s) {
        
        string c="";
        
        for(int i=0;i<s.size();i++){
            
            if(s[i]=='*'){
                if(c != "") c.pop_back();
            }else{
                c+=s[i];
            }
            
        }
        return c;
    }
};
class Solution {
public:
    
    static bool compareStrings(const std::string &a, const std::string &b) {
        if (a.length() == b.length()) {
            return a < b;  // Lexicographically compare strings of equal length
        }
        return a.length() < b.length();  // Compare strings by length
    }
    
    string findLongestWord(string s, vector<string>& dictionary) {
        
        string ans = "";
        int n = s.length();
        
        sort(dictionary.begin(), dictionary.end(), compareStrings);
        
//         for(int i=0; i<dictionary.size(); i++)
//             cout << dictionary[i] << "  ";
        
        for(int i=dictionary.size()-1; i>=0; i--)
        {
            if(dictionary[i].length() < ans.length()) break;
            
            int p1 = 0, p2 = 0, match_c = 0;
            
            while(p1<n && p2<dictionary[i].length())
            {
                if(s[p1]==dictionary[i][p2])
                {
                    match_c++;
                    p2++;
                }    
                p1++;
            }
            
            if(match_c == dictionary[i].length())
            {
               ans = dictionary[i];
            }
                
        }
        
         return ans;
    }
};
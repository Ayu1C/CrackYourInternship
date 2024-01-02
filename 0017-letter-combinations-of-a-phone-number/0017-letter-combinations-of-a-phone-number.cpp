class Solution {
public:
    
    void backtrack(string combination, string digits, map<char, string>& buttons, vector<string>& output)
    {
        if(digits.length()==0)
        {
            output.push_back(combination);
            return;
        } else{
            
            for(char c : buttons[digits[0]])
            {
                backtrack(combination + c, digits.substr(1), buttons, output);
            }
        }
    }
    
    
    vector<string> letterCombinations(string digits) {
        
        map<char, string> buttons;
        buttons['2'] = "abc"; buttons['3'] = "def"; buttons['4'] = "ghi"; buttons['5'] = "jkl"; buttons['6'] = "mno"; buttons['7'] = "pqrs"; buttons['8'] = "tuv"; buttons['9'] = "wxyz";
        
        
        if(digits.length()==0) return {};
        
         vector<string> output;
        
        backtrack("", digits, buttons, output);
        
        return output;
        
    }
};
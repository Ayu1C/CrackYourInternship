class Solution {

public:
    bool checkValidString(string s) {
        
       // cmax counts the maximum open parenthesis,
       // which means the maximum number of unbalanced '(' that COULD be paired.
       // cmin counts the minimum open parenthesis,
       // which means the number of unbalanced '(' that MUST be paired.
        
        int unmatchedLeft = 0;  
        // unmatched left parenthesis, since scan from left to right, only check at the end of loop.
        int maxRightNeeded = 0; 
        // maximal right parenthesis needed, need to check while scanning from left to right.
        for (char c : s) {
            if (c == '(')
                unmatchedLeft++, maxRightNeeded++;
            if (c == ')')
                maxRightNeeded--, unmatchedLeft = max(unmatchedLeft - 1, 0); 
            if (c == '*')
                maxRightNeeded++, unmatchedLeft = max(unmatchedLeft - 1, 0);
            if (maxRightNeeded < 0) //found extra right parenthesis
                return false;
        }
        return unmatchedLeft == 0;

    }
};
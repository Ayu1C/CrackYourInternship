class Solution {
public:
    bool isValid(string s) {
         
        stack<int> stack;
        
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i] == '[')
            {
                stack.push(s[i]);
            }
            else if(s[i]==')')
            {
                if(stack.empty()==true) return false;
                char temp = stack.top();
                if(temp != '(') return false;
                else stack.pop();
            }
            else if(s[i]=='}')
            {
                if(stack.empty()==true) return false;
                char temp = stack.top();
                if(temp != '{') return false;
                else stack.pop();
            }
            else if(s[i]==']')
            {
                if(stack.empty()==true) return false;
                char temp = stack.top();
                if(temp != '[') return false;
                else stack.pop();
            }
        }
        if(stack.empty()==true) return true;
        else return false;
    }
};
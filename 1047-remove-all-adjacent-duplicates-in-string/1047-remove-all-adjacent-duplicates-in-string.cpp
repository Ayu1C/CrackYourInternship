class Solution {
public:
    string removeDuplicates(string s) {
         int n = s.length(), i=0;
        
        stack<int> st;
        st.push(s[i]);
        i++;
        
        while(i<n)
        {
           if(!st.empty() && s[i]==st.top())
           {
              while(!st.empty() && s[i] == st.top())
              {
                  st.pop();
              } 
               i++;
           }
            else
            {
               st.push(s[i]);
               i++; 
            }
        }
        
        string ans = "";
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
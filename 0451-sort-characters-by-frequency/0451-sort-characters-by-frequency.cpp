class Solution {
public:
    string frequencySort(string s) {
        
        map<char, int> freq;
        
        for(int i=0; i<s.length(); i++)
        {
            freq[s[i]]++;
        }    
        
        priority_queue<pair<int, char>, vector<pair<int, char>>> pq;
        
        for(auto i : freq){
            pq.push({i.second, i.first});
        }
        
        string ans = "";
        
        while(ans.length()<s.length())
        {
           pair<int, char> temp = pq.top();
            while(temp.first--)
            {
                ans += temp.second;
            }
            pq.pop();
        }
        
        return ans;
    }
};
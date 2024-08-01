class Solution {
public:
    int countSeniors(vector<string>& details) {
       
        int count = 0;
        
        for(int i=0; i<details.size(); i++) {
            
            string person = details[i];
            int age = stoi(person.substr(11, 2));
            
            if(age > 60) count++;
        }
        
        return count;
    }
};
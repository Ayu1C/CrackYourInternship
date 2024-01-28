class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        
        sort(asteroids.begin(), asteroids.end());
        
        long long total_mass = mass;
        
        bool ans = true;
        
        for(int i=0; i<asteroids.size(); i++)
        {
            if(total_mass >= asteroids[i])
            {
                total_mass += asteroids[i];
            }
            else
            {
                ans = false;
                break;
            }
        }
        
        return ans;
    }
};
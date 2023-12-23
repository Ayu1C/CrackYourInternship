class Solution {
public:
    bool isPathCrossing(string path) {
        
        int n = path.length();
        
//         map<char, int> mp;
//         mp['N'] = 0, mp['S'] = 0, mp['E'] = 0, mp['W'] = 0;
        
//         for(int i=0; i<n; i++)
//         {
//             if(i != 0 && ((path[i]=='E' && path[i-1]=='W') || (path[i]=='W' && path[i-1]=='E') ||
//                (path[i]=='S' && path[i-1]=='N') || (path[i]=='N' && path[i-1]=='S')))
//                 return true;
            
            
//             mp[path[i]]++;
//             if((mp['N']>=mp['S'] && mp['E']>=mp['W']) || 
//                (mp['E']==0 && mp['W']==0 && mp['N'] != 0 && mp['S'] != 0) ||
//                (mp['N']==0 && mp['S']==0 && mp['E'] != 0 && mp['W'] != 0))
//                 return true;
//         }
        
//         return false;
        
        int x=0, y=0;
        set<pair<int,int>> points;
        points.insert(make_pair(0,0));
        
        for(int i=0; i<n; i++)
        {
            if(path[i] == 'E') x++;
            else if(path[i] == 'W') x--;
            else if(path[i] == 'N') y++;
            else y--;
            
            pair<int, int> temp = make_pair(x, y);
            
            if(points.find(temp) != points.end()) return true;
            
            points.insert(temp);
        }
        
        
        return false;
    }
};
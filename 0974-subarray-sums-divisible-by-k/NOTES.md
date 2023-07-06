        THIS IS A BRUTE FORCE APPROACH, WHERE WE FIND ALL SUBARRAYS, WE CHECK WHETHER THE SUM OF ALL ELEMENTS OF THE SUBARRAY IS DIVISIBLE BY K OR IF SUM IS EQUAL TO 0 BCZ 0 IS DIVISIBLE BY EVERY INTEGER. WE'LL INCREMENT COUNT IF SUM FOUND DIVISIBLE BY K. THE TIME COMPLEXITY OF THIS APPROACH WILL BE O(N^3)
        
        
        int n = nums.size();
        int count = 0, cursum=0;
        
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                for(int p=i; p<=j; p++)
                {
                   cursum += nums[p]; 
                }
                if(cursum % k == 0 || cursum==0) count++;
                cursum = 0;
            }
        }
        return count; 
        
        
        THIS ONE IS IN O(N^2) TIME COMPLEXITY, WE ARE USING PREFIX SUM VECTOR TO REMOVE ONE LOOP FROM BRUTE FORCE APPROACH
        
        int n = nums.size();
        
        if(n==1)
        {
            if(nums[0]%k==0 || nums[0]==0) return 1;
            else return 0;
        }
        
        int count = 0, cum_sum = 0;
        vector<int> prefix(n);
        
        for(int i=0; i<n; i++)
        {
           cum_sum += nums[i];
           prefix[i] = cum_sum; 
           if(prefix[i]%k == 0 || prefix[i]==0) count++;
        }

        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
            {
               if(((prefix[j]-prefix[i]) % k == 0) || ((prefix[j]- prefix[i]) == 0))
                   count++;
            }
        }
        return count; 
        
        
        THIRD APPROACH - suppose s1 is sum from index 0 to 1 and s2 is sum from index 0 to 6, now if s1 % k == s2 % k; and let s1 = mk + x and s2 = nk + x, here remainder is x;
        
        So, s2-s1 = nk + x - mk - x i.e. s2-s1 = k(n-m);
        It means if remainder of s1 and s2 are same when divided by k, then their difference will be divisible by k.
            
        So, we will use a map here, to store the remainder of sum obtained so far, and every time we visit next index, we will check whwther the remainder of sum here is present in map or not, if it is present , then we can increse our count by the value map[remainder]; and also increment map[remainder]
        
        And also we will initially keep 0 in map with value 1, it means we have one remainder as 0, now in future if we get our remainder as 0, that actually means sum is divisible be k, then we will increase count;
          
        int cursum = 0, count = 0, remainder;
        map<int, int> map;
        
        map[0] = 1;
        
        for(int i=0; i<nums.size(); i++)
        {
            cursum += nums[i];
            remainder = ((cursum % k) + k) % k; // to get positive remainder if cursum is negative
            
            if(map.find(remainder) != map.end())
            {
                count += map[remainder];
                map[remainder]++;
            }
            else
                map[remainder] = 1;
        }
         
        return count;  
        ​

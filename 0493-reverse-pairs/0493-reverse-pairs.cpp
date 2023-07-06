class Solution {
public:
    void merge(vector<int> &nums, int begin, int mid, int end, int &count)
    {
        int j = mid+1;
        for(int i=begin; i<=mid; i++)
        {
            while(j<=end && nums[i]>2*(long long)nums[j])
            {
                j++;
            }
            count += j-(mid+1);
        }
        
        int s = end - begin + 1;
        vector<int> temp(s, 0);
        
        int left = begin, right = mid+1, k=0;
        while(left<=mid && right<=end){
            if(nums[left] < nums[right]){
                temp[k] = nums[left];
                k++; left++;
            }
            else{
                temp[k++] = nums[right++];
            }
        }
        while(left<=mid){
            temp[k++] = nums[left++]; 
        }
        while(right<=end){
            temp[k++] = nums[right++]; 
        }
        
        int m=0;
        for(int i=begin; i<=end; i++){
            nums[i] = temp[m++];
        }
        
        
    }
    
    void mergeSort(vector<int> &nums, int begin, int end, int &count) 
    {
       if(begin>=end) return;
        
        int mid = (begin+end)/2;
        
        mergeSort(nums, begin, mid, count);
        mergeSort(nums, mid+1, end, count);
        merge(nums, begin, mid, end, count);
    }
    
    
    int reversePairs(vector<int>& nums) {
        
        int count = 0;
        
        mergeSort(nums, 0, nums.size()-1, count);
        return count;
        
    }
};
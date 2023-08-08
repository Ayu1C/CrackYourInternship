class Solution {
public:
   int search(vector<int>& nums, int target) {
    int n = nums.size();
    int beg = 0, end = n - 1, mid;
    while (beg <= end) {
        mid = beg + (end - beg) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[beg] <= nums[mid]) {
            if (target >= nums[beg] && target < nums[mid]) {
                end = mid - 1;
            } else {
                beg = mid + 1;
            }
        } else{
            if (target > nums[mid] && target <= nums[end]) {
                beg = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }
    return -1;
}
};
    
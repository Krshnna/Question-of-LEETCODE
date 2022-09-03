class Solution {
public:
    
    int left_bin(vector<int> &nums, int key) { // for leftmost occurence
        
        int low = 0, high = nums.size() - 1;
        int mid = low + (high - low) / 2; // better way to find the middle element
        int ans = -1;
        
        while(low <= high) {
            
            int mid = low + (high - low) / 2;
            
            if(nums[mid] == key) {
                ans = mid;
                high = mid - 1;   // just go and keep searching for leftmost target value
            }
            else if(nums[mid] < key) 
                low = mid + 1;
            
            else 
                high = mid - 1;
        }
        return ans;
    }
    
    int right_bin(vector<int> &nums, int key) { // for rightmost occurence
        
        int low = 0, high = nums.size() - 1; 
        int mid = low + (high - low) / 2;
        int ans = -1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] == key) {
                ans = mid;
                low = mid + 1;  // just go and keep searching for leftmost target value
            }
            else if(nums[mid] < key) 
                low = mid + 1;
            else 
                high = mid - 1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
            
        int ans1 = left_bin(nums, target);
        int ans2 = right_bin(nums, target);
        
       return {ans1, ans2};  // since there are only two indices to return 
         
    }
};

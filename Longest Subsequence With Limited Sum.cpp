class Solution {
public:
    
    int bin_search(vector<int> &nums, int key, int low, int high) {
        
        int res = 0;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(nums[mid] == key) return mid;
            
            else if(nums[mid] < key) {
                res = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        
        return res;
        
    }
    
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        
        int low = 0, high = nums.size() - 1; 
        
        sort(nums.begin(), nums.end());
        
        for(int i = 1; i < nums.size(); i++) {
            nums[i] = nums[i - 1] + nums[i]; 
        }
        
        
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++) {
            
            int sum = queries[i];
            if(sum < nums[0])
                 ans.push_back(0);
            
           else {
                int su = bin_search(nums, sum, low, high);
                ans.push_back(su + 1);      
           }
        }
        return ans;
    }
};

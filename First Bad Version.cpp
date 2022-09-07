// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n;
        
        int ans = 0;
        
        while(low <= high) {
            
            int mid = low + (high - low) / 2;
            
            int is_bad = isBadVersion(mid);
            
            if(is_bad == 1) {
                ans = mid;
                high = mid - 1;
            }
            else if(is_bad == 0) low = mid + 1;
            // else high = mid - 1;
        }
        
        return ans;
    }
};

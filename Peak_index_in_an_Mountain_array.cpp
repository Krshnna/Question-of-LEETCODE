class Solution {
public:
    int findPeak(vector<int> &arr) {
        
        int low = 0, high = arr.size() - 1;
        int mid;
        while(low <= high) {
            
            if(low == high and mid == low) return mid;  // final answer will return here
            
            mid = low + (high - low) / 2;  // efficient way to find middle element
            
            if(arr[mid] < arr[mid + 1]) low = mid + 1;
            else high = mid;
        }
        return -1;    // since function of int type but function will never end here
    }
    int peakIndexInMountainArray(vector<int>& arr) {
        
        return findPeak(arr); // call for function 
        
    }
};

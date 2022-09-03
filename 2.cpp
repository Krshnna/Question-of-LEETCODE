//{ Driver Code Starts

#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int left_bin(int *arr, int size, int key) {
	    
	    int low = 0, high = size - 1;
	    int ans = -1;
	    
	    while(low <= high) {
	        int mid = low + (high - low) / 2;
	        if(arr[mid] == key) {
	            ans = mid;
	            high = mid - 1;
	        }
	        else if(arr[mid] < key) low = mid + 1;
	        else high = mid - 1;
	    }
	    return ans;
	}
	
	int right_bin(int *arr, int size, int key) {
	    int low = 0, high = size - 1;
	    int ans = -1;
	    
	    while(low <= high) {
	        int mid = low + (high - low) / 2;
	        if(arr[mid] == key) {
	            ans = mid;
	            low = mid + 1;
	        }
	        else if(arr[mid] < key) low = mid + 1;
	        else high = mid - 1;
	    }
	    return ans;
	}
	
	int count(int arr[], int n, int x) {
	    
	    int left_idx = left_bin(arr, n, x);
	    int right_idx = right_bin(arr, n, x);
	    
	   if(left_idx == -1 and right_idx == -1) return 0;
	    
	    return abs(left_idx - right_idx) + 1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends

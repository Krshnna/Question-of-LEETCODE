//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int findPivot(int *arr, int low, int high) {
        
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(arr[mid] >= arr[0]) {
                low = mid + 1;
            }
            else high = mid;
        }
        return low;
    }
    
    int bin_search(int *arr, int low, int high, int key) {
        
        while(low <= high) {
            int mid = low + (high - low) /2;
            
            if(arr[mid] == key) return mid;
            else if(arr[mid] < key) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
    
    int search(int a[], int l, int h, int key){
        
        int pivot = findPivot(a, l, h);
        // cout << pivot << " ";
        
        if(key >= a[pivot] and key <= a[h - 1]) {
            return bin_search(a, pivot, h, key);
        }
        else return bin_search(a, 0, pivot - 1, key);
        
        return 0;
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends

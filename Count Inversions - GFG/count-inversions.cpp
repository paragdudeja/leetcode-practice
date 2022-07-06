// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        return mergeSort(arr, 0, N-1);
    }
    
    long long mergeSort(long long arr[], int low, int high) {
        if(low >= high) return 0;
        
        long long count = 0;
        
        int mid = low + (high - low)/2;
        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid+1, high);
        count += merge(arr, low, mid, high);
        
        return count;
    }
    
    long long merge(long long arr[], int low, int mid, int high) {
        int n1 = mid - low + 1;
        int n2 = high - mid;
        
        long long A[n1], B[n2];
        for(int i = 0; i < n1; i++) A[i] = arr[i + low];
        for(int j = 0; j < n2; j++) B[j] = arr[j + mid + 1];
        
        int i = 0, j = 0, k = low;
        long long count = 0;
        
        while(i < n1 && j < n2) {
            if(A[i] <= B[j]) {
                arr[k++] = A[i++];
            }
            else {
                arr[k++] = B[j++];
                count += (n1 - i);
            }
        }
        while(i < n1) arr[k++] = A[i++];;
        while(j < n2) arr[k++] = B[j++];
        
        return count;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends
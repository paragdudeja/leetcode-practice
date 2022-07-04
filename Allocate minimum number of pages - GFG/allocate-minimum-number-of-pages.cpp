// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if(M > N ||  M <= 0) return -1;
        
        int total = A[0];
        int max_pages_in_book = A[0]; 
        for(int i = 1; i < N; i++) {
            total += A[i];
            max_pages_in_book = max(max_pages_in_book, A[i]);
        }
        
        int low = max_pages_in_book, high = total;
        int ans = low;
        
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(isPossible(A, N, M, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
    
    bool isPossible(int A[], int N, int M, int guess) {
        int count = 1;
        int sum = 0;
        for(int i = 0; i < N; i++) {
            if(sum + A[i] > guess) {
                sum = A[i];
                count++;
            }
            else {
                sum += A[i];
            }
        }
        return count <= M;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends
// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int countMinOperations(int arr[], int n) {
        int steps = 0;
        while(true) {
            int i;
            int zero_count = 0;
            
            for(i = 0; i < n; i++) {
                if(arr[i] & 1) {
                    break;    
                }
                if(arr[i] == 0) {
                    zero_count++;
                }
            }
            
            if(zero_count == n)
                break;
            
            if(i == n) {
                for(i = 0; i < n; i++) {
                    arr[i] /= 2;
                }
                steps++;
            }
            for(i = 0; i < n; i++) {
                if(arr[i] & 1) {
                    arr[i]--;
                    steps++;
                }
            }
                
        }
        return steps;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.countMinOperations(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
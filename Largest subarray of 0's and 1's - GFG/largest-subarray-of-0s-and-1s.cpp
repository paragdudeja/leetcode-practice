// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method*/

// arr[] : the input array containing 0s and 1s
// N : size of the input array

// return the maximum length of the subarray
// with equal 0s and 1s
class Solution{
  public:
    // TC : O(N)
    // SC : O(N)
    int maxLen(int arr[], int N)
    {
        unordered_map<int, int> mp;
        int sum = 0;
        mp[0] = -1;
        
        int max_len = 0;
         
         for(int i = 0; i < N; i++) {
             sum += arr[i] == 1 ? 1 : -1;
             if(mp.find(sum) != mp.end()) {
                 max_len = max(max_len, i - mp[sum]);
             }
             else {
                 mp[sum] = i;
             }
         }
         
        return max_len;
    }
};


// { Driver Code Starts.

int main()
{
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.maxLen(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends
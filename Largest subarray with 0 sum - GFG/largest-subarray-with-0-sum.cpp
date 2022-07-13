// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    // TC : O(N)
    // SC : O(N)
    int maxLen(vector<int>&A, int n)
    {   
        int longest = 0;
        unordered_map<int, int> mp;
        int sum = 0;
        mp[0] = -1;
        
        for(int i = 0; i < n; i++) {
            sum += A[i];
            if(mp.find(sum) == mp.end()) {
                mp[sum] = i;
            }
            else {
                longest = max(longest, i - mp[sum]);
            }
        }
        return longest;
    }
    
    
    /*
    Brute
    // TC : O(N^2)
    // SC : O(1)
    int maxLen(vector<int>&A, int n) {
        int longest = 0;
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum += A[j];
                if(sum == 0) {
                    longest = max(longest, j - i + 1);
                }
            }
        }
        return longest;
    }
    
    */
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends
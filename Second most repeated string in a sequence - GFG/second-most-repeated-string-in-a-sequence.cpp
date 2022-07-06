// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        unordered_map<string, int> mp;
        for(int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }
        
        
        int mx1 = INT_MIN, mx2 = INT_MIN;
        string ans;
        for(auto it: mp) {
            if(it.second > mx1) {
                mx2 = mx1;
                mx1 = it.second;
            }
            else if(it.second > mx2) {
                // ans = it.first;
                mx2 = it.second;
            }
        }
        
        for(auto it: mp) {
            if(it.second == mx2) {
                ans = it.first;
                break;
            }
        } 
        
        return ans;
        
        // vector<pair<int, string>> v;
        // for(auto it: mp) v.push_back({it.second, it.first});
        
        // sort(v.begin(), v.end());
        // int s = v.size();
        // return v[s-2].second;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends
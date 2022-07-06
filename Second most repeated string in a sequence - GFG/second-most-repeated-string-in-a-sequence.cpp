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
        
        vector<pair<int, string>> v;
        for(auto it: mp) v.push_back({it.second, it.first});
        
        sort(v.begin(), v.end());
        int s = v.size();
        return v[s-2].second;
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
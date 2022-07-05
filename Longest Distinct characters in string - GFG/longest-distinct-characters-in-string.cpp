// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int longestSubstrDistinctChars (string S)
{
    int longest = 0;
    int start = 0;
    // int n = S.size();
    vector<bool> seen(26);
    
    for(int i = 0; i < S.size(); i++) {
        if(seen[S[i] - 'a']) {
            while(S[start] != S[i]) {
                seen[S[start++] - 'a'] = false;
            }
            start++;
        }
        seen[S[i] - 'a'] = true;
        longest = max(longest, i - start + 1);
    }
    return longest;
}
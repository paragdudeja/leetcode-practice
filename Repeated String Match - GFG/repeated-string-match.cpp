// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution{

    public:
    int repeatedStringMatch(string a, string b) 
    {
        string tmp;
        int count = b.length() / a.length();
        for(int i = 0; i < count; i++) {
            tmp += a;
        }
        // cout << tmp << endl;
        if(tmp.find(b) != string::npos) return count;
        count++;
        tmp += a;
        if(tmp.find(b) != string::npos) return count;
        count++;
        tmp += a;
        if(tmp.find(b) != string::npos) return count;
        return -1;
    }
  
};

// { Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution obj;
        cout<<obj.repeatedStringMatch(A,B)<<"\n";
    }
    return 0;
}
  // } Driver Code Ends
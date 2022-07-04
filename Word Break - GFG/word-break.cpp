// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int wordBreak(string A, vector<string> &B) {
        unordered_set<string> words(B.begin(), B.end());
        return solve(0, A, words);
    }
    
    bool solve(int index, string A, unordered_set<string> &words) {
        if(index == A.size())
            return 1;
        
        string word;
        for(int i = index; i < A.size(); i++) {
            word.push_back(A[i]);
            if(words.count(word) && solve(i+1, A, words))
                return 1;
        }
        return 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends
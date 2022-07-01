// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        for(int i = N-2; i >= 0; i--) {
            for(int j = 0; j < N; j++) {
                int op1 = j == 0 ? 0 : Matrix[i+1][j-1];
                int op2 = Matrix[i+1][j];
                int op3 = j == N-1 ? 0 : Matrix[i+1][j+1];
                Matrix[i][j] += max({op1, op2, op3});
            }
        }
        return *max_element(Matrix[0].begin(), Matrix[0].end());
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
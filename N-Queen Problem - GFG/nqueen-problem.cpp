// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans;
        vector<vector<int>> board(n , vector<int>(n, 0));
        
        vector<int> curr;
        solve(0, n, board, curr, ans);
        
        return ans;
    }
    
    void solve(int col, int n, vector<vector<int>> &board, vector<int> &curr, vector<vector<int>> &ans) {
        if(col == n) {
            ans.push_back(curr);
            return;
        }
        
        for(int row = 0; row < n; row++) {
            if(isSafe(row, col, n, board)) {
                board[row][col] = 1;
                curr.push_back(row+1);
                solve(col + 1, n, board, curr, ans);
                board[row][col] = 0;
                curr.pop_back();
            }
        }
    }
    
    bool isSafe(int row, int col, int n, vector<vector<int>> &board) {
        for(int j = 0; j < col; j++) {
            if(board[row][j]) return false;
        }
        
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j]) return false;
        }
        
        for(int i = row, j = col; i < n && j >= 0; i++, j--) {
            if(board[i][j]) return false;
        }
        return true;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends
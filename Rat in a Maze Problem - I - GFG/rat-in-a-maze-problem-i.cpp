// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> result;
        string path;
        helper(0, 0, n, m, path, result);
        return result;
    }
    
    void helper(int i, int j, int n, vector<vector<int>> &m, string path, vector<string> &result) {
        if(i < 0 || i == n || j < 0 || j == n || m[i][j] == 0) return;
        if(i == n-1 && j == n-1) {
            result.push_back(path);
            return;
        }
        m[i][j] = 0;
        helper(i + 1, j, n, m, path + "D", result);
        helper(i - 1, j, n, m, path + "U", result);
        helper(i, j + 1, n, m, path + "R", result);
        helper(i, j - 1, n, m, path + "L", result);
        m[i][j] = 1;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<int> current;
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        vector<int> updated;
        for(int i = 0; i < candidates.size(); i++) {
            if(i > 0 && candidates[i] == candidates[i-1]) continue;
            updated.push_back(candidates[i]);
        }
        solve(0, target, updated, current, result);
        return result;
    }
    
    void solve(int index, int target, vector<int>& candidates, vector<int> &current, vector<vector<int>> &result) {
        if(index == candidates.size()) {    
            return;
        }
        if(target == 0) {
            result.push_back(current);
            return;
        }
        
        // if(index > 0 && candidates[index] == candidates[index-1])
        //     solve(index + 1, target , candidates, current, result);
        
        if(candidates[index] <= target) {
            current.push_back(candidates[index]);
            solve(index, target - candidates[index], candidates, current, result);
            current.pop_back();
        }
        
        solve(index + 1, target , candidates, current, result);
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends
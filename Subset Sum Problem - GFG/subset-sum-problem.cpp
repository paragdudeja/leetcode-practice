// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int N = arr.size();
        vector<bool> prev(sum+1);
        prev[0] = true;
        
        for(int i = 1; i <= N; i++) {
            vector<bool> current(sum+1);
            current[0] = true;
            
            for(int j = 1; j <= sum; j++) {
                    if(arr[i-1] <= j)
                        current[j] = prev[j - arr[i-1]] || prev[j];
                    else
                        current[j] = prev[j];
            }
            
            for(int j = 1; j <= sum; j++)
                prev[j] = current[j];
        }
        
        return prev[sum];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends
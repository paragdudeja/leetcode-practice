// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int height[], int n){
        // int n = height.size();
        
        // Right Max
        int rightMax[n];
        rightMax[n-1] = height[n-1];
        
        for(int i = n - 2; i >= 0; i--) 
            rightMax[i] = max(rightMax[i + 1], height[i]); 
        
        int leftMax = 0;
        long long totalWater = 0;
        
        for(int i = 0; i < n; i++) {
            leftMax = max(leftMax, height[i]);
            totalWater += min(leftMax, rightMax[i]) - height[i];
        }
        
        return totalWater;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends
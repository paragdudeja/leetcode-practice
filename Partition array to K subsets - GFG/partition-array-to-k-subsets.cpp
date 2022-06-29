// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    bool isKPartitionPossible(int a[], int n, int k)
    {
        if(k == 1) return 1;
        if(k > n) return 0;
        int total = 0;
        for(int i = 0; i < n; i++)
            total += a[i];
        if(total % k  != 0) return false;
        vector<bool> used(n);
        return helper(0, 0, 0, total/k, k, a, n, used);
    }
    
    bool helper(int index, int bucketNum, int bucketSum, int reqSum, int k,
               int nums[], int n, vector<bool> &used) {
        if(bucketNum == k) return true;
        if(bucketSum == reqSum) { // base case
            return helper(0, bucketNum+1, 0, reqSum, k, nums, n, used);
        }
        if(bucketSum > reqSum) {
            return false;
        }
        if(index >= n) {
            return false;
        }
        
        if(used[index]) { // Number is already used
            return helper(index+1, bucketNum, bucketSum, reqSum, k, nums, n, used);
        }
        else { // Not used
            // Pick
            bucketSum += nums[index];
            used[index] = true;
            bool option1 = helper(index+1, bucketNum, bucketSum, reqSum, k, nums, n, used);
            used[index] = false;
            bucketSum -= nums[index];
            
            // Not Pick
            bool option2 = helper(index+1, bucketNum, bucketSum, reqSum, k, nums, n, used);
            
            return option1 or option2;
        }
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}  // } Driver Code Ends
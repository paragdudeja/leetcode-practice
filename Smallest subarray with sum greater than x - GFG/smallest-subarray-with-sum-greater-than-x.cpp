// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        int min_len = INT_MAX;
        
        int start = 0;
        int curr_len = 0;
        int sum = 0;
        
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            curr_len++;
            while(sum > x) {
                min_len = min(min_len, curr_len);
                sum -= arr[start++];
                curr_len--;
            }
        }
        
        return min_len;
    }
};

// { Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}  // } Driver Code Ends
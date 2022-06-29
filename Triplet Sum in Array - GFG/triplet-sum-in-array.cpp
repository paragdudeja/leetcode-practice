// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        bool flag = false;
        sort(A, A+n);
        for(int first = 0; first < n && !flag; first++) {
            int second = first + 1;
            int third = n - 1;
            while(second < third) {
                int sum = A[first] + A[second] + A[third];
                if(sum == X){
                    flag = true;
                    break;
                }
                else if(sum < X)
                    second++;
                else
                    third--;
            }
        }
        return flag;
    }

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends
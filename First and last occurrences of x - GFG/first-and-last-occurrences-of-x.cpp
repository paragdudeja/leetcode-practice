// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

int getLowerBound(int arr[], int n, int x) {
    int ans = n;
    int low = 0, high = n - 1;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}

int getUpperBound(int arr[], int n, int x) {
    int ans = n;
    int low = 0, high = n - 1;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if(arr[mid] > x) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}

vector<int> find(int arr[], int n , int x )
{
    int lb = getLowerBound(arr, n, x);
    int ub = getUpperBound(arr, n, x);
    if(lb == ub)
        return {-1, -1};
    else
        return {lb, ub-1};
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends
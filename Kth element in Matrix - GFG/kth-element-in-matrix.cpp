// { Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}
// } Driver Code Ends


int getRank(int mat[MAX][MAX], int n, int guess) {
    int rank = 0;
    int i = n-1, j = 0;
    while(i >= 0 &&  j < n) {
        if(mat[i][j] <= guess) {
            rank += i+1;
            j++;
        }
        else {
            i--;
        }
    }
    return rank;
}

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    int low = mat[0][0], high = mat[n-1][n-1];
    int ans = low;
    while(low <= high) {
        int mid = low + (high - low)/2;
        int rank = getRank(mat, n, mid);
        if(rank >= k) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}

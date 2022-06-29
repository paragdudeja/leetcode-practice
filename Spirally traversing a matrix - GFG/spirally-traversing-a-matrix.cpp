// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int> result(r * c);
        int idx = 0;
        
        int top = 0, bottom = r - 1, left = 0, right = c - 1;
        
        while(top <= bottom && left <= right) {
            // Top row, left to right
            for(int j = left; j <= right; j++) {
                result[idx++] = matrix[top][j];
            }
            top++;
            if(top > bottom) break;
            
            // Right column, top to  bottom
            for(int i = top; i <= bottom; i++) {
                result[idx++] = matrix[i][right];
            }
            right--;
            if(left > right) break;
            
            // Bottom row, right yo left
            for(int j = right; j >= left; j--) {
                result[idx++] = matrix[bottom][j];
            }
            
            bottom--;
            if(top > bottom) break;
            
            // Left column, bottom to top
            for(int i = bottom; i >= top; i--) {
                result[idx++] = matrix[i][left];
            }
            left++;
        }
        
        return result;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
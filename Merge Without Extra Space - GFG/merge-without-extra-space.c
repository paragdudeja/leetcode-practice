// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdlib.h>


 // } Driver Code Ends
//User function Template for C


//Function to merge the arrays.
void merge(int arr1[], int arr2[], int n, int m)
{ 
    int i = 0, j = 0;
    int total = n + m;
    int gap = total/2 + (total&1);
    while(gap > 0) {
        for(int i = 0; i + gap < total; i++) {
            int j = i, k = i + gap;
            if(j < n && k < n) { // Both in arr1
                if(arr1[j] > arr1[k]) {
                    // swap(arr1[j], arr1[k]);
                    int temp = arr1[j];
                    arr1[j] = arr1[k];
                    arr1[k] = temp;
                }
            }
            else if(j < n && k >= n) { // one in arr1 and other  in arr2
                k -= n;
                if(arr1[j] > arr2[k]) {
                    // swap(arr1[j], arr2[k]);
                    int temp = arr1[j];
                    arr1[j] = arr2[k];
                    arr2[k] = temp;
                }
            }
            else { // both in arr2;
                j -= n;
                k -= n;
                if(arr2[j] > arr2[k]) {
                    // swap(arr2[j], arr2[k]);
                    int temp = arr2[j];
                    arr2[j] = arr2[k];
                    arr2[k] = temp;
                }
            }
        }
        // gap /= 2;
        if(gap == 1) gap = 0;
        else {
            int newgap = gap/2 + (gap&1);
            gap = newgap;
        }
    }
}

// { Driver Code Starts.

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n,m;
		scanf("%d", &n);
		scanf("%d", &m);
		int *arr1;
		arr1 = (int*)malloc(n * sizeof(int));
		for(int i=0;i<n;i++)
    		scanf("%d", &arr1[i]);
		int *arr2;
		arr2 = (int*)malloc(m * sizeof(int));
		for(int i=0;i<m;i++)
    		scanf("%d", &arr2[i]);
    	
    	merge(arr1,arr2,n,m);
    	for(int i=0;i<n;i++)
    		printf("%d ", arr1[i]);
		for(int i=0;i<m;i++)
    		printf("%d ", arr2[i]);
    	printf("\n");
	}
	return 0;
}  // } Driver Code Ends
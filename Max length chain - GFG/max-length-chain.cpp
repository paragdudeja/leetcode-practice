// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
int maxChainLen(struct val p[],int n)
{
    sort(p, p + n, [](auto &v1, auto &v2){
        return v1.second < v2.second;
    });
    
    int last = 0;
    int count = 1;
    
    for(int i = 1; i < n; i++) {
        if(p[i].first > p[last].second) {
            last = i;
            count++;
        }
    }
    return count;
}
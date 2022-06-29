// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
		vector<string>find_permutation(string S)
		{
		    set<string> result;
		    perm(0, S, result);
		    vector<string> res;
		    for(auto it: result)
		        res.push_back(it);
		    return res;
		}
		
		void perm(int index, string &s, set<string> &res) {
		    if(index == s.size()) {
		        res.insert(s);
		        return;
		    }
		    
		    for(int i = index; i < s.size(); i++) {
		        swap(s[index], s[i]);
		        perm(index + 1, s, res);
		        swap(s[index], s[i]);
		    }
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends
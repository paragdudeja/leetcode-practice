// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
		vector<string>find_permutation(string S)
		{
		    vector<string> result;
		    perm(0, S, result);
		    sort(result.begin(), result.end());
		    return result;
		}
		
		void perm(int index, string &s, vector<string> &res) {
		    if(index == s.size()) {
		        res.push_back(s);
		        return;
		    }
		    
		    unordered_set<char> us;
		    for(int i = index; i < s.size(); i++) {
		        if(us.count(s[i])) continue;
		        us.insert(s[i]);
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
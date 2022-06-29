// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> st;
        for(char &c: x) {
            if(c == '(' || c == '{' || c == '[')
                st.push(c);
            else {
                if(!st.empty() && isMatched(c, st.top()))
                    st.pop();
                else
                    return false;
                
            }
        }
        return st.empty();
    }
    
    bool isMatched(char ch, char top) {
        return (top == '(' && ch == ')') || (top == '{' && ch == '}') || (top == '[' && ch == ']');
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends
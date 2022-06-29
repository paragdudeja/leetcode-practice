// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        int index = 0;
        return makeTree(0, n-1, index, in, pre);
    }
    
    Node *makeTree(int left, int right, int &index, int in[], int pre[]) {
        if(left > right) return nullptr;
        
        int pivot = left;
        for(int i = left; i <= right; i++) {
            if(in[i] == pre[index]) {
                pivot = i;
                break;
            }
        }
        
        Node *root = new Node(pre[index]);
        // root->data = pre[index];
        index++;
        
        root->left = makeTree(left, pivot-1, index, in, pre);
        root->right = makeTree(pivot+1, right, index, in, pre);
        
        return root;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends
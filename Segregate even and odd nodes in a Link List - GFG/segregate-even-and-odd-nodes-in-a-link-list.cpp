// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head) {
        Node *oddHead = new Node(0), *oddTail = oddHead;
        Node *evenHead = new Node(0), *evenTail = evenHead;
        
        while(head) {
            if(head->data & 1) { // odd
                oddTail->next = head;
                oddTail = oddTail->next;
            }
            else {
                evenTail->next = head;
                evenTail = evenTail->next;
            }
            head = head->next;
        }
        oddTail->next = NULL;
        evenTail->next = oddHead->next;
        return evenHead->next;
    }
    /*
    Node* divide(int N, Node *head){
        Node *oddHead = NULL,*oddTail = NULL, *evenHead = NULL, *evenTail=NULL, *curr = head;
        while(curr){
            if(curr->data &1){
                if(oddHead == NULL){
                    oddHead = curr;
                    oddTail = curr;
                }
                else{
                    oddTail->next = curr;
                    oddTail = curr;
                }
                curr = curr->next;
            }
            else{
                if(evenHead == NULL){
                    evenHead = curr;
                    evenTail = curr;
                }
                else{
                    evenTail->next = curr;
                    evenTail = curr;
                }
                curr = curr->next;
            }
        }
        if(oddTail) oddTail->next = NULL;
        if(evenTail) evenTail->next = oddHead;
        if(evenHead)
            return evenHead;
        return oddHead;
    }
    */
};

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
  // } Driver Code Ends
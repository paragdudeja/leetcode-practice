// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++



class TrieNode {
private:
    TrieNode *links[26];
    int count;
public:
    TrieNode() {
        count = 0;
        for(int i = 0; i < 26; i++) {
            links[i] = NULL;
        }
    }
    
    TrieNode *getNode(char ch) {
        return links[ch - 'a'];
    }
    
    void putNode(char ch, TrieNode *node) {
        links[ch - 'a'] = node;
    }
    
    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }
    
    int getCount() {
        return count;
    }
    
    void incrementCount() {
        count++;
    }
};

class Trie {
private:
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(const string &word) {
        TrieNode *node = root;
        for(const char &ch: word) {
            if(!node->containsKey(ch)) {
                node->putNode(ch, new TrieNode());
            }
            node = node->getNode(ch);
            node->incrementCount();
        }
    }
    
    string getShortestUniquePrefix(string word) {
        TrieNode *node = root;
        string result;
        for(const char &ch: word) {
            result.push_back(ch);
            node = node->getNode(ch);
            if(node->getCount() == 1) {
                break;
            }
        }
        return result;
    }
};

class Solution
{
    public:
    vector<string> findPrefixes(string arr[], int n)
    {
        Trie *trie = new Trie();
        for(int i = 0; i < n; i++) {
            trie->insert(arr[i]);
        }
        
        vector<string> result;
        for(int i = 0; i < n; i++) {
            result.push_back(trie->getShortestUniquePrefix(arr[i]));
        }
        return result;
    }
    
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";


        cout << "\n";

    }

    return 0;
}
  // } Driver Code Ends
class TrieNode {
private:
    TrieNode* links[26];
public:
    TrieNode() {
        for(int i = 0; i < 26; i++) {
            links[i] = NULL;
        }
    }
    
    bool contains(char ch) {
        return links[ch - 'a'] != NULL;
    }
    
    TrieNode* get(char ch) {
        return links[ch - 'a'];
    }
    
    void put(char ch, TrieNode *node) {
        links[ch - 'a'] = node;
    }
    
    void insert(string &word) {
        TrieNode *node = this;
        for(char &ch: word) {
            if(!node->contains(ch)) {
                node->put(ch, new TrieNode());
            }
            node = node->get(ch);
        }
    }
    
    bool isLeaf() {
        for(int i = 0; i < 26; i++) {
            if(links[i] != NULL) {
                return false;
            }
        }
        return true;
    }
    
    void sumDepths(int depth, int &ans) {
        if(this->isLeaf()) {
            ans += depth;   
        }
        else {
            for(int i = 0; i < 26; i++) {
                if(this->links[i] != NULL) {
                    this->links[i]->sumDepths(depth+1, ans);
                }
            }
        }
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        TrieNode *root = new TrieNode();
        for(string &s: words) {
            reverse(s.begin(), s.end());
            root->insert(s);
        }
        
        int minLen = 0;
        root->sumDepths(1, minLen);
        return minLen;
        
    }
};
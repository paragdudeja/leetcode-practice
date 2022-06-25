/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {\
        if(!node) return nullptr;
        vector<Node*> copies(101, nullptr);
        
        // BFS
        queue<Node*> q;
        q.push(node);
        copies[node->val] = new Node(node->val);
        
        while(!q.empty()) {
            auto currentNode = q.front();
            q.pop();
            
            for(auto neighbor: currentNode->neighbors) {
                if(copies[neighbor->val] == nullptr) {
                    copies[neighbor->val] = new Node(neighbor->val);
                    q.push(neighbor);
                    
                }
                copies[currentNode->val]->neighbors.push_back(copies[neighbor->val]);
            }
        }
        return copies[node->val];
    }
};
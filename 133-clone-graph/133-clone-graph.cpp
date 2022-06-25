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
        vector<Node*> clones(101, nullptr);
        
        // BFS
        queue<Node*> q;
        q.push(node);
        clones[node->val] = new Node(node->val);
        
        while(!q.empty()) {
            auto currentNode = q.front();
            q.pop();
            auto clonedNode = clones[currentNode->val];
            for(auto neighbor: currentNode->neighbors) {
                if(clones[neighbor->val] == nullptr) {
                    clones[neighbor->val] = new Node(neighbor->val);
                    q.push(neighbor);
                    
                }
                clonedNode->neighbors.push_back(clones[neighbor->val]);
            }
        }
        return clones[node->val];
    }
};
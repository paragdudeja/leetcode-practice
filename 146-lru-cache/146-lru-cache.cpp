class Node {
public:
    int key;
    int val;
    Node *next;
    Node *prev;
    Node(int _key, int _val) {
        key = _key;
        val = _val;
        next = prev = NULL;
    }
};

class LRUCache {
public:
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    
    int cap;
    unordered_map<int, Node*> m;
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node *node) {
        Node *temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
    }
    
    void deleteNode(Node *node) {
        Node *delprev = node->prev;
        Node *delnext = node->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        // delete node;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) return -1;
        Node *node = m[key];
        int val = node->val;
        m.erase(key);
        deleteNode(node);
        addNode(node);
        m[key] = head->next;
        
        return val;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()) {
            Node *node = m[key];
            m.erase(key);
            deleteNode(node);
        }
        if(m.size() == cap) {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
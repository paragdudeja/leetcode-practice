class LRUCache {
    unordered_map<int, list<int>::iterator> address;
    unordered_map<int, int> mp;
    list<int> l;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        
        int val = mp[key];
        
        auto it = address[key];
        l.erase(it);
        address.erase(key);
        
        l.push_front(key);
        address[key] = l.begin();
        
        return val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            auto it = address[key];
            l.erase(it);
            
            
        }
        else if(mp.size() == cap) {
            int k = l.back();
            auto it = address[k];
            l.erase(it);
            address.erase(k);
            mp.erase(k);
        }
        l.push_front(key);
        address[key] = l.begin();
        mp[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
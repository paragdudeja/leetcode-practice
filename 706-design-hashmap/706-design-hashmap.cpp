class MyHashMap {
    vector<list<pair<int, int>>> m;
    int siz;
public:
    MyHashMap() {
        siz = 1000;
        m.resize(siz);
    }
    
    int hash(int key) {
        return key % siz;
    }
    
    list<pair<int, int>>::iterator search(int key) {
        int h = hash(key);
        list<pair<int, int>>::iterator it = m[h].begin();
        while(it!=m[h].end()){
            if(it->first == key)
                break;
            it++;
        }
        return it;
    }
    
    void put(int key, int value) {
        int h = hash(key);
        list<pair<int, int>>::iterator it = search(key);
        if(it == m[h].end()) 
            m[h].push_back({key, value});
        else 
            it->second = value;
    }
    
    int get(int key) {
        int h = hash(key);
        list<pair<int, int>>::iterator it = search(key);
        return it == m[h].end() ? -1 : it->second;
    }
    
    void remove(int key) {
        int h = hash(key);
        list<pair<int, int>>::iterator it = search(key);
        if(it != m[h].end()) m[h].erase(it);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
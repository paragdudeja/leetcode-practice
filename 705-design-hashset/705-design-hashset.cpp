class MyHashSet {
    vector<list<int>> m;
    int siz;
public:
    MyHashSet() {
        siz = 1000;
        m.resize(siz);
    }
    
    int hash(int key) {
        return key % siz;
    }
    
    list<int>::iterator search(int key) {
        int h = hash(key);
        return find(m[h].begin(), m[h].end(), key);
    }
    
    void add(int key) {
        if(contains(key)) return;
        int h = hash(key);
        m[h].push_back(key);
    }
    
    void remove(int key) {
        list<int>::iterator it = search(key);
        int h = hash(key);
        if(it != m[h].end())
            m[h].erase(it);
        
    }
    
    bool contains(int key) {
        int h = hash(key);
        return search(key) != m[h].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
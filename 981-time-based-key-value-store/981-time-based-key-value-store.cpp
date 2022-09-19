class TimeMap {
public:
    map<string, set<int>> ds;
    map<int, string> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        ds[key].insert(timestamp);
        mp[timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        string value;
        if(ds[key].size() == 0) return value;
        auto it = ds[key].upper_bound(timestamp);
        if(it != ds[key].begin()) {
            --it;
            value = mp[*it];
        }
        return value;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
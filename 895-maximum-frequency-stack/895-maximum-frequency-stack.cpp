class FreqStack {
public:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> mp;
    int maxFreq;
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        ++freq[val];
        mp[freq[val]].push(val);
        if(maxFreq < freq[val]) {
            maxFreq = freq[val];
        }
    }
    
    int pop() {
        int val = mp[maxFreq].top();
        mp[maxFreq].pop();
        --freq[val];
        if(mp[maxFreq].empty()) {
            --maxFreq;
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
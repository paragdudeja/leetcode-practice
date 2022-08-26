class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> num_hash = get_hash(n);
        for(int i = 0; i < 31; ++i) {
            if(num_hash == get_hash(1 << i)) {
                return true;
            }
        }
        return false;
    }
    
    vector<int>  get_hash(int num) {
        vector<int> hash(10);
        while(num > 0) {
            int digit = num % 10;
            num /= 10;
            hash[digit]++;
        }
        
        return hash;
    }
    
    /*
    bool reorderedPowerOf2(int n) {
        int t = 1;
        string s = to_string(n);
        sort(s.begin(), s.end());
        bool flag = false;
        while(t > 0) {
            string tmp = to_string(t);
            sort(tmp.begin(), tmp.end());
            if(tmp == s) {
                flag = true;
                break;
            }
            else {
                t <<= 1;
            }
        }
        return flag; 
    }
    */
};
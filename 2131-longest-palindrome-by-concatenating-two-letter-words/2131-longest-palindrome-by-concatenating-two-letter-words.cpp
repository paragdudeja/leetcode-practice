class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        // unordered_multiset<string> s;
        unordered_map<string, int> m;
        int ans = 0;
        for(string &word: words)
            m[word]++;
        
        for(auto it: m) {
            string key = it.first;
            if(key[0]!=key[1]){
                swap(key[0], key[1]);
                if(m.count(key)){
                    int t = min(m[key], m[it.first]);
                    // cout<<t<<' '<<key<<' ';
                    ans += (t*4);
                    m.erase(key);
                    // m.erase(it.first);
                }
            }
            else {
                ans += (m[key]/2 * 4);
            }
        }
        
        for(auto it: m){
            string word = it.first;
            if(word[0]==word[1] && it.second & 1){
                ans += 2;
                break;
            }
        }
        return ans;
    }
};
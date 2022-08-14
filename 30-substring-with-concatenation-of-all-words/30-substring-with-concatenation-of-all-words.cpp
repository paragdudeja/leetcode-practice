class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
    vector<int> ans;
        unordered_map<string, int> mp;
        for(auto i:words){
            mp[i]++;
        }
        
        int left=0, size=words[0].size(), count=mp.size(), total=size*words.size();
        if(total>s.size()){
            return ans;
        }
        
        for(int i=0; i<=s.size()-total; i++){
            unordered_map<string, int> mp2;
            int temp=count;
            for(int j=i; j<i+total; j+=size){
                string curr=s.substr(j, size);
                if(mp.find(curr)!=mp.end()){
                    mp2[curr]++;
                    if(mp2[curr]==mp[curr]){
                        --temp;
                    }
                    if(mp2[curr]>mp[curr]){
                        break;
                    }
                }else{
                    break;
                }
                if(temp==0){
                    ans.push_back(i);
                }
            }
        }
        
        return ans;
    }
    /*
    vector<int> findSubstring(string s, vector<string>& words) {
        int len = words[0].size();
        if(s.size() < len * words.size()) return vector<int>();
         
        unordered_map<string, int> mp;
        
        for(auto &word: words) {
            mp[word]++;
        }
        
        vector<int> ans;
        for(int i = 0; i <= s.size() - len * words.size(); ++i) {
            unordered_map<string, int> copy_map = mp;
            
            for(int j = 0; j < words.size(); ++j) {
                
                string sub = s.substr(i + j*len, len);
                if(copy_map.count(sub)) {
                    if(--copy_map[sub] == 0) {
                        copy_map.erase(sub);
                    }
                    if(copy_map.size() == 0) {
                        ans.push_back(i);
                        break;
                    }
                }
                else {
                    break;
                }
            }
        }
        return ans;
    }
    */
};
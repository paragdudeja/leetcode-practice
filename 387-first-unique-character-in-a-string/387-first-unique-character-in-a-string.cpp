class Solution {
public:
    int firstUniqChar(string s) {
        int state[26];
        int res = INT32_MAX;
        memset(state, -1, sizeof(int)*26);
        for(int i=0; i<s.length(); i++){
            if(state[s[i]-'a']==-1)
                state[s[i]-'a'] = i;
            else
                state[s[i]-'a'] = -2;
        }
        for(int i=0; i<26; i++)
            if(state[i]>=0)
                res = min(res, state[i]);
        return res==INT32_MAX? -1: res;
    }
};
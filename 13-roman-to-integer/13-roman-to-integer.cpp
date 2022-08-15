class Solution {
public:
    int romanToInt(string s) {
        int mp[256];
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int ans = 0;
        ans += mp[s[0]];
        for(int i=1; i<s.length(); i++) {
            ans += mp[s[i]];
            if(mp[s[i-1]] < mp[s[i]])
                ans -= 2*mp[s[i-1]];
        }
        return ans;
    }
};
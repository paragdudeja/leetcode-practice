class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a==b) return -1;
        else return max((int)a.size(),(int)b.size());
    }
};
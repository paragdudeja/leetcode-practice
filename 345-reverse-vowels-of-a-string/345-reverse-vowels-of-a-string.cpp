class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size()-1;
        
        string vowels = "aAeEiIoOuU";
        
        while(i < j) {
            while(i < j && vowels.find(s[i])==string::npos ) i++;
            while(i < j && vowels.find(s[j])==string::npos) j--;
            // cout << i << ' ' << j << endl;
            if(i >= j) break;
            swap(s[i++], s[j--]);
        }
        
        return s;
    }
    
};
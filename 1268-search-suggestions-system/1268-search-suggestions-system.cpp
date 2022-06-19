class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        sort(products.begin(), products.end());
        
        string current = "";
        for(int i = 0; i < (int)searchWord.size(); i++) {
            current.push_back(searchWord[i]);
            vector<string> res;
            for(const string &s: products) {
                if(s.substr(0, i+1) == current) {
                    res.push_back(s);
                }
                if(res.size() == 3)
                    break;
            }
            ans.push_back(res);
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        sort(products.begin(), products.end());
        
        string current = "";
        for(int i = 0; i < (int)searchWord.size(); i++) {
            current.push_back(searchWord[i]);
            vector<string> res;
            auto it = lower_bound(products.begin(), products.end(), current);
            for(int i = 0; i < 3 && it != products.end(); it++, i++) {
                string s = *it;
                if(s.find(current)) break;
                res.push_back(s);
            }
            ans.push_back(res);
        }
        return ans;
    }
};
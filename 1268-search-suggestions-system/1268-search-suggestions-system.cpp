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
                if(it->find(current)) break;
                res.push_back(*it);
            }
            ans.push_back(res);
        }
        return ans;
    }
};
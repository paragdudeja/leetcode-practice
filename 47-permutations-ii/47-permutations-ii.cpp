class Solution {
public:
    void helper(int i, vector<int> num, vector<vector<int> > &res) {
        if (i == num.size() -1) {
            res.push_back(num);
            return;
        }
        for (int j = i; j < num.size(); j++) {
            if (i != j && num[i] == num[j]) continue;
            swap(num[i], num[j]);
            helper(i+1, num, res);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> >res;
        helper(0, num, res);
        return res;
    }
};
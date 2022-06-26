class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> name, city;
        vector<int> time, amount;
        int n = transactions.size();
        string s;
        vector<string> res; 
        
        for(auto &transaction: transactions) {
            stringstream ss(transaction);
            getline(ss, s, ',');
            name.push_back(s);
            getline(ss, s, ',');
            time.push_back(stoi(s));
            getline(ss, s, ',');
            amount.push_back(stoi(s));
            getline(ss, s, ',');
            city.push_back(s);
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(amount[i] > 1000 || (name[i]==name[j] && abs(time[i]-time[j])<=60 && city[i]!=city[j])) {
                    res.push_back(transactions[i]);
                    break;
                }
            }
        }
        
        return res;
    }
};
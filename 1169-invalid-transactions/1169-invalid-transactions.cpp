class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> name;
        vector<int> time;
        vector<int> amount;
        vector<string> city;
        
        for(string &t: transactions) {
            stringstream ss(t);
            string s;
            getline(ss, s, ',');
            name.push_back(s);
            getline(ss, s, ',');
            time.push_back(stoi(s));
            getline(ss, s, ',');
            amount.push_back(stoi(s));
            getline(ss, s, ',');
            city.push_back(s);
        }
        
        vector<string> invalid;
        int n = name.size();
        for(int i = 0; i < n; i++) {
            // cout << name[i] << ' ' << time[i] << ' ' << amount[i] << ' ' << city[i] << endl; 
            for(int j = 0; j < n; j++) {
                if(amount[i]>1000 || (name[i] == name[j] && abs(time[i] - time[j]) <= 60 && city[i] != city[j])) {
                    invalid.push_back(transactions[i]);
                    break;
                }
            }
        }
        
        return invalid;
    }
};
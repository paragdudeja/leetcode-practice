class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastOcc(26, -1);
        for(int i = 0; i < s.size(); i++)
            lastOcc[s[i] - 'a'] = i;
        
        vector<int> partitions;
        int mx_index = 0;
        int start = -1;
        for(int i = 0; i < s.size(); i++) {
            mx_index = max(mx_index, lastOcc[s[i] - 'a']);
            if(i == mx_index) {
                partitions.push_back(i - start);
                start = i;
            }
        }
        return partitions;
    }
};
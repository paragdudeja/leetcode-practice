class Solution {
public:
    static bool comp(vector<int> &v1, vector<int> &v2){
        return v1[1] < v2[1];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), comp);
        int mx = 1, last = 0;
        for(int i=1; i<n; i++){
            if(pairs[i][0] > pairs[last][1]){
                mx++;
                last = i;
            }
        }
        return mx;
    }
};
class Solution {
public:    
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        int mid = n/2;
        // if(n&1) mid++;
        unordered_map<int,int> m;
        for(auto &x: arr)
            m[x]++;
        
        vector<int> v;
        
        for(auto &item: m){
            v.push_back(item.second);
        }
        sort(v.begin(),v.end());
        int c=0;
        for(int i=v.size()-1;i>=0;i--){
            mid -= v[i];
            c++;
            if(mid<=0) break;
        }
        
        
        
        return c;
    }
};
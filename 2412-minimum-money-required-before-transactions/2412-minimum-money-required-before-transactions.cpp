class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        vector<vector<int>> dip,nodip;
        for(auto i:transactions)
        {
            if(i[0]>=i[1])
                dip.push_back(i);
            else
                nodip.push_back(i);
        }
        sort(dip.begin(),dip.end(),[](auto &a,auto &b){
           if(a[1]==b[1])
               return a[0]>b[0];
            return a[1]<b[1];
        });
        sort(nodip.begin(),nodip.end(),[](auto &a,auto &b){
           
               return a[0]>b[0];
            
        });
        long long ans=INT_MAX,temp=0;
        for(auto i:dip)
        {
            temp-=i[0];
            ans=min(ans,temp);
            temp+=i[1];
        }
        for(auto i:nodip)
        {
            temp-=i[0];
            ans=min(ans,temp);
            temp+=i[1];
        }
        return -ans;
    }
};
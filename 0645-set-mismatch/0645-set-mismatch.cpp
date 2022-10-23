class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> s;
        int sum = 0, a;
        int n = nums.size();
        for(int &num: nums){
            // sum += num;
            if(s.count(num)){
                a = num;
            }
            else{
                s.insert(num);
                sum += num;
            }
        }
        return {a, n*(n+1)/2 - sum};
    }
};
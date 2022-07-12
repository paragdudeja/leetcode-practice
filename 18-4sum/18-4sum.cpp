class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        
        for(int first = 0; first < n; first++) {
            for(int second = first+1; second < n; second++) {
                int third = second + 1, fourth = n - 1;
                while(third < fourth) {
                    long long sum = (long long)nums[first] + nums[second] + nums[third] + nums[fourth];
                    if(sum == target) {
                        ans.push_back({nums[first], nums[second], nums[third], nums[fourth]});
                        while(third < fourth && nums[third] == nums[third+1]) third++;
                        while(third < fourth && nums[fourth] == nums[fourth-1]) fourth--;
                        third++;
                        fourth--;
                    }
                    else if(sum < target) {
                        third++;
                    }
                    else {
                        fourth--;
                    }
                }
                while(second + 1 < n && nums[second] == nums[second+1]) second++;
            }
            while(first + 1 < n && nums[first] == nums[first+1]) first++;
        }
        
        return ans;
    }
    
    /*
    // TC : O(N^3 * LogN) + O(N logN) (sort)
    // SC : O(M*4) (M is number of quads)
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> sv;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    long long x = (long long)target - (long long)nums[i] - (long long)nums[j] - (long long)nums[k];
                    if(binarySearch(nums, k+1, n-1, x)) {
                        sv.insert({nums[i], nums[j], nums[k], (int)x});
                    }
                }
            }
        }
        
        vector<vector<int>> res(sv.begin(), sv.end());
        return res;
    }
    
    bool binarySearch(vector<int> &nums, int low, int high, long long x) {
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(nums[mid] == x) {
                return true;
            }
            else if(nums[mid] < x) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return false;
    }
    */
};
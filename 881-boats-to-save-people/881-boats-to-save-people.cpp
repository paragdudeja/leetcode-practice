class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int left = 0, right = people.size() - 1;
        int count = 0;
        while(left < right) {
            // cout << left << ' ' << right << endl;
            if(people[left] + people[right] <= limit) {
                left++;
            }
            right--;
            count++;
        } 
        return count + (left==right);
    }
};
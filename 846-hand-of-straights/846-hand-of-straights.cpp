class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(), hand.end());
        unordered_map<int, int> m;
        for(int x: hand) {
            m[x]++;
        }
        
        for(int x: hand) {
            if(m[x] == 0) continue;
            m[x]--;
            for(int i = 1; i < groupSize; ++i) {
                if(m[x+i] == 0) return false;
                m[x+i]--;
            }
        }
        return true;
    }
};
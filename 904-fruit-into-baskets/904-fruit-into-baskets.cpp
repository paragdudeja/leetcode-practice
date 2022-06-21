class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int mx = 0;
        int start = 0;
        int n = fruits.size();
        int type1 = -1, type2 = -1;
        int count1 = 0, count2 = 0;
        
        for(int i = 0; i < n; i++) {
            if(type1 == fruits[i]) {
                count1++;
            }
            else if(type2 == fruits[i]) {
                count2++;
            }
            else if(type1 == -1) {
                type1 = fruits[i];
                count1 = 1;
            }
            else if(type2 == -1) {
                type2 = fruits[i];
                count2 = 1;
            }
            else {
                while(true) {
                    if(fruits[start++] == type1) {
                        if(count1 == 1) {
                            type1 = fruits[i];
                            break;
                        }
                        else {
                            count1--;
                        }
                    }
                    else {
                        if(count2 == 1) {
                            type2 = fruits[i];
                            break;
                        }
                        else {
                            count2--;
                        }
                    }
                }
            }
            mx = max(mx, i - start + 1);
        }
        return mx;
    }
};
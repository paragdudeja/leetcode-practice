class Solution {
public:
    bool isRobotBounded(string instructions) {
        bool up = true, down = false, left = false, right = false;
        int x = 0, y = 0;
        for(char &ch: instructions) {
            if(ch == 'G') {
                if(up) y++;
                else if(down) y--;
                else if(left) x--;
                else x++;
            }
            else if(ch == 'L') {
                if(up) {
                    up = false;
                    right = true;
                }
                else if(left) {
                    left = false;
                    up = true;
                }
                else if(down) {
                    down = false;
                    left = true;
                }
                else {
                    right = false;
                    down = true;
                }
            }
            else { // R
                if(up) {
                    up = false;
                    left = true;
                }
                else if(left) {
                    left = false;
                    down = true;
                }
                else if(down) {
                    down = false;
                    right = true;
                }
                else {
                    right = false;
                    up = true;
                }
            }
        }
        
        return (x==0 && y==0) || !up;
    }
};
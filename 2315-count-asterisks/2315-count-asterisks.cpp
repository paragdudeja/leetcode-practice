class Solution {
public:
    int countAsterisks(string s) {
        int lineCount = 0;
        int ast = 0;
        for(char &c: s) {
            if(c == '|') lineCount++;
            if(c == '*' && lineCount%2 == 0) ast++;
        }
        return ast;
    }
};
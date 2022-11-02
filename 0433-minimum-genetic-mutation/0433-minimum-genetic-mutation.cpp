class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> visited{start};
        unordered_set<string> genes(bank.begin(), bank.end());
        vector<char> choices{'A', 'C', 'G', 'T'};
        
        int steps = 0;
        queue<string> q;
        q.push(start);
        
        while(!q.empty()) {
            int count = q.size();
            for(int i = 0; i < count; ++i) {
                string current = q.front();
                q.pop();
                
                if(current == end) return steps;
                
                for(char &ch: current) {
                    char tmp = ch;
                    for(char &choice: choices) {
                        ch = choice;
                        if(genes.count(current) == 1 && visited.count(current) == 0) {
                            visited.insert(current);
                            q.push(current);
                        }
                    }
                    ch = tmp;
                } 
            }
            ++steps;
        }
        return -1;
    }
};
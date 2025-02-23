class Solution {
    public:
        string predictPartyVictory(string s) {
            queue<int> a, b;
            for(int i = 0; i < s.size(); i++) if (s[i] == 'R') a.push(i); else b.push(i);
    
            int i = 0;
            while(true) {
                if (!a.size()) return "Dire";
                if (!b.size()) return "Radiant";
                auto cura = a.front(), curb = b.front();
                if (cura < curb) {
                    b.pop();
                    a.pop();
                    a.push(s.size()+i);
                } else {
                    a.pop();
                    b.pop();
                    b.push(s.size()+i);
                }
                i++;
            }
            return "HEELLO";
        }
            
        
    };
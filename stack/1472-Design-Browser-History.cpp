class BrowserHistory {
    public:
        stack<string> st1;
        stack<string> st2;
        BrowserHistory(string homepage) {
            st1.push(homepage);
            st2 = stack<string>();
    
        }
        
        void visit(string url) {
            st1.push(url); 
            st2 = stack<string>();
        }
        
        string back(int steps) {
            int i = min(steps,(int) st1.size()-1);
            while(i--) {
                st2.push(st1.top());
                st1.pop();
            }
            return st1.top();
        }
        
        string forward(int steps) {
            int i = min(steps, (int)st2.size());
            while(i--){
                st1.push(st2.top());
                st2.pop();
            }
            return st1.top();
        }
    };
    
    
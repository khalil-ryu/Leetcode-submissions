/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

 class NestedIterator {
    public:
        queue<int> q;
        NestedIterator(vector<NestedInteger> &nestedList) {
            for(auto & x : nestedList) {
                if(x.isInteger())
                    solve_integer(x);
                else
                    solve_list(x.getList());
            }
        }
        void solve_integer(NestedInteger & x) {
            q.push(x.getInteger());
        }
        void solve_list( vector<NestedInteger> & x) {
            for(auto y : x) {
                if(y.isInteger())
                    solve_integer(y);
                else
                    solve_list(y.getList());
            }
        }
        int next() {
            auto cur = q.front();
            q.pop();
            return cur;
        }
        
        bool hasNext() {
            return q.size();
        }
    };
    
    /**
     * Your NestedIterator object will be instantiated and called as such:
     * NestedIterator i(nestedList);
     * while (i.hasNext()) cout << i.next();
     */
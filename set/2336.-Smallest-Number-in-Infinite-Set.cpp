class SmallestInfiniteSet {
    public:
        set<int> st;
        int i = 1;
        SmallestInfiniteSet() {
            st.insert(1);
        }
        
        int popSmallest() {
            if (i <= *st.begin()) {
                int x = *st.begin();
                st.erase(x);
                st.insert(x+1);
                i++;
                return x;
            } else {
                int x = *st.begin();
                st.erase(x);
                return x;
            }
            
            return 0;
        }
        
        void addBack(int num) {
            st.insert(num);
        }
    };
    
    /**
     * Your SmallestInfiniteSet object will be instantiated and called as such:
     * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
     * int param_1 = obj->popSmallest();
     * obj->addBack(num);
     */
class NumberContainers {
    public:
        unordered_map<int, int> mp1;
        unordered_map<int, set<int>> mp2;
        NumberContainers() {
        }
        
        void change(int index, int number) {
            if (mp1.find(index) != mp1.end()) {
                int x = mp1[index];
                mp1[index] = number;
                mp2[x].erase(index);
                if (mp2[x].size() == 0) mp2.erase(x);
                if (mp2.find(number) == mp2.end()) mp2[number] = {index};
                else mp2[number].insert(index);
            } else {
                mp1[index] = number;
                if (mp2.find(number) == mp2.end()) mp2[number] = {index};
                else mp2[number].insert(index);
            }
    
        }
        
        int find(int number) {
            return mp2.find(number) == mp2.end() ? -1 : *(mp2[number].begin());
        }
    };
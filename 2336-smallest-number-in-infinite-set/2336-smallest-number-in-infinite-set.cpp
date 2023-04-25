class SmallestInfiniteSet {
public:
    set<int> s;
    int ctr = 1;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if(!s.empty()){
            int val = *s.begin();
            s.erase(*s.begin());
            return val;
        }
        return ctr++;
    }
    
    void addBack(int num) {
        if(num<ctr)
            s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
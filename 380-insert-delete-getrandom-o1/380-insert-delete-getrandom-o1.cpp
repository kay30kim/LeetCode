class RandomizedSet {
private:
    set<int> rset;
public:
    RandomizedSet() {
        rset.clear();
    }
    
    bool insert(int val) {
        if(rset.find(val)!=rset.end())
            return false;
        else{
            rset.insert(val);
            return true;
        }
    }
    
    bool remove(int val) {
        if(rset.find(val)!=rset.end()){
            rset.erase(val);
            return true;
        }else
            return false;
    }
    
    int getRandom() {
        set<int>::iterator it = rset.begin();
        int num = rand()%rset.size();
        advance(it,num);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
class MyHashMap {
private:
    static const int hsize = 1000001;
    struct Hash{
        int key, value;
        Hash* next = 0; // member access within misaligned address 0xbebebebebebebe for type 'MyHashMap::Hash', which requires 8 byte alighnment
        Hash* alloc(int _key, int _value, Hash* _next){
            key = _key; value = _value; next = _next;
            return this;
        }
    }hash[hsize],hbuf[10001];
    int idx;
public:
    MyHashMap() {
        //for(int i=0; i<hsize; i++) hash[i].next = NULL;
        //for(int i=0; i<10001; i++) hbuf[i].next = NULL;
        idx=0;
    }
    void put(int key, int value) {
        //printf("입력 : %d %d\n",key,value);
        hash[key].next = hbuf[idx++].alloc(key,value,hash[key].next);
        Hash *p = hash[key].next;
        while(p){
            //printf("%d %d\n",p->key,p->value);
            p = p->next;
        }
    }
    
    int get(int key) {
        Hash *p = hash[key].next;
        if(p) return p->value;
        else return -1;
    }
    
    void remove(int key) {
        hash[key].next = NULL;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
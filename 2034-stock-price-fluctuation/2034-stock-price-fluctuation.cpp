class StockPrice {
private:
    struct Point{
        int timestamp;
        int price;
        int cnt;
    };
    struct compare {
        bool operator()(Point a, Point b){
            return a.price>b.price;
        }
    };
    struct compare2 {
        bool operator()(Point a, Point b){
            return a.price<b.price;
        }
    };
    // heap 사용
    priority_queue<Point, vector<Point>, compare> minHeap;
    priority_queue<Point, vector<Point>, compare2> maxHeap;
    unordered_map<int,Point> hash;
    int cur, cnt;
public:
    StockPrice() {
        minHeap = priority_queue<Point, vector<Point>, compare>();
        maxHeap = priority_queue<Point, vector<Point>, compare2>();
        hash.clear();
        cur = 0;
        cnt=1;
    }
    
    void update(int timestamp, int price) {
        if(hash.find(timestamp)!=hash.end()){
            cnt++;
            maxHeap.push({timestamp,price,cnt});
            minHeap.push({timestamp,price,cnt});    
        }else{
            maxHeap.push({timestamp,price,cnt});
            minHeap.push({timestamp,price,cnt});    
        }
        hash[timestamp].cnt = cnt;
        // cur = timestamp; ㅡㅡ;
        cur = max(cur, timestamp);
        hash[timestamp].price = price;
        //printf("%d %d\n",maxHeap.top().price,minHeap.top().price);
    }
    
    int current() {
        return hash[cur].price;
    }
    
    int maximum() {
        while(maxHeap.top().cnt != hash[maxHeap.top().timestamp].cnt)
            maxHeap.pop();
        return maxHeap.top().price;
    }
    
    int minimum() {
        while(minHeap.top().cnt != hash[minHeap.top().timestamp].cnt)
            minHeap.pop();
        return minHeap.top().price;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
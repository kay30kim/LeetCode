class Logger {
private:
    map<string,int> hash;
public:
    Logger() {
        hash.clear();
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(hash[message] == 0 || timestamp-hash[message]>=9){
            hash[message] = timestamp+1;
            return true;
        }
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
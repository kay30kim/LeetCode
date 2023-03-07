class Solution {
    
    struct Point{
        string word;
        int cnt;
    };
    struct comp{
        bool operator()(Point a, Point b){
            if(a.cnt<b.cnt) return true;
           else if(a.cnt==b.cnt) return a.word>b.word;
            else return false;
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string, int> hash;
        priority_queue<Point,vector<Point>,comp> pq;
        for(auto word:words){
            hash[word]++;
        }
        for(auto it:hash){
     pq.push({it.first,it.second});
        }
        for(int i=0; i<k; i++){
            ans.push_back(pq.top().word);
            pq.pop();
        }
        return ans;
    }
};
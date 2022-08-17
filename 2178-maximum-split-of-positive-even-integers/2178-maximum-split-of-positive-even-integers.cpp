class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> ans;
        if(finalSum%2==1) return ans;
        
        int num =2;
        while(finalSum-num>=num+2){
            ans.push_back(num);
            finalSum-=num;
            num+=2;            
        }
        ans.push_back(finalSum);
        return ans;
    }
};
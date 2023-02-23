class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=prices[0], ans=0;
        if(prices.size()==0) return 0;
        for(auto price : prices){
            if(min>price) min = price;
            if(min<price && price-min>ans){
                ans = price-min;
            }
        }
        return ans;
    }
};
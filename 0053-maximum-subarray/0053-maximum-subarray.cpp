class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0, ans=nums[0];
        for(auto num:nums){
            sum+=num;
            if(sum<num) sum=num;
            if(sum>ans) ans=sum;
            //printf("%d %d\n",sum,ans);
        }
        return ans;
    }
};
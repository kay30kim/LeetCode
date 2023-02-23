class Solution {
public:
    int divideConquer(int left, int right, vector<int>& nums){
        if(left>=right) return nums[left];
        
        int mid = (left+right)/2;
        int curr = 0;
        int bestLeftSum = 0;
        int bestRightSum = 0;
        //printf("%d %d %d\n",left,mid,right);
        for(int i=mid-1 ; i >=left; i--){
            curr += nums[i];
            bestLeftSum = max(bestLeftSum,curr);
            //printf("%d %d\n",i,nums[i]);
        }
        
        curr = 0;
        for(int i=mid+1; i<=right; i++){
            //printf("%d %d\n",i,nums[i]);
            curr +=nums[i];
            bestRightSum = max(bestRightSum,curr);
        }
        
        int bestCombinSum = nums[mid] + bestLeftSum + bestRightSum;
        
        int leftHalf = divideConquer(left,mid-1,nums);
        int rightHalf = divideConquer(mid+1,right,nums);
        //printf("%d %d %d\n",bestCombinSum,leftHalf,rightHalf);
        return max(bestCombinSum, max(leftHalf, rightHalf));
    }
    int maxSubArray(vector<int>& nums) {
        return divideConquer(0,nums.size()-1,nums);
    }
};
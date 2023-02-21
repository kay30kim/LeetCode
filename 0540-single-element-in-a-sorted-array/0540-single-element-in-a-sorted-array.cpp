class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int lo = 0, hi = nums.size()-1, mid;
        while(lo<=hi){
            mid = (lo+hi)/2;
            //printf("lo = %d, hi = %d, mid = %d nums[mid] = %d %d\n",lo, hi,mid,nums[mid],nums[mid+1]);
            if(mid-1>=0 && nums[mid]==nums[mid-1]){
                if((mid-1)%2==1){
                    hi=mid-2;
                }else{
                    lo=mid+1;
                }
            }else if(mid+1<nums.size() && nums[mid]==nums[mid+1]){
                if((mid)%2==1){
                    hi=mid-1;
                }else{
                    lo=mid+2;
                }
            }else{
                //printf("come");
                return nums[mid];
            }
            printf("%d %d %d\n",lo,mid,hi);
        }
        return 0;
    }
};
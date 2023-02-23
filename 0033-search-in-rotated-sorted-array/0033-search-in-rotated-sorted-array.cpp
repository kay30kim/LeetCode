class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int left, int right){
        while(left<=right){            
            int mid = (left+right)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        if(left==right){
            if(nums[left]==target) return 0;
            else return -1;
        }
        
        int left1, right1, left2, right2;
        if(nums[0]<nums[nums.size()-1]){
            return binarySearch(nums,target,0,nums.size()-1);
        }else{
            while(left<=right){
                int mid = (left+right)/2;
                if(nums[left]<nums[right]) {
                    left2 = left;
                    break;
                }
                if(mid>0 && nums[mid-1]>nums[mid]){
                    left2 = mid;
                    break;
                }
                if(mid+1<nums.size() && nums[mid]>nums[mid+1]){
                    left2 = mid+1;
                    break;
                }
                
                if(nums[mid]>nums[right]) left = mid+1;
                else if(nums[mid]<nums[0]) right= mid-1;
            }
        }
        left1 = 0;
        right1 = left2-1;
        right2 = nums.size()-1;
        int ans1 = binarySearch(nums,target,left1,right1);
        int ans2 = binarySearch(nums,target,left2,right2);
        
        if(ans1==-1 && ans2==-1) return -1;
        else return ans1<ans2?ans2:ans1;
    }
};
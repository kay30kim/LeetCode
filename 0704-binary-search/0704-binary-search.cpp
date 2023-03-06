class Solution {
private:
    int idx = -1;
public:
    void binarySearch(vector<int>& nums, int left, int right, int target){
        if(left>right) return;
        else if (left==right){
            if(nums[left]==target) idx = left;
            return;
        }
        int mid = (left+right)/2;
        if(nums[mid]>target) binarySearch(nums,left,mid,target);
        else if(nums[mid]<target) binarySearch(nums,mid+1,right,target);
        else idx = mid;
    }
    int search(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int left = 0, right = nums.size()-1;
        binarySearch(nums,left,right,target);
        return idx;
    }
};
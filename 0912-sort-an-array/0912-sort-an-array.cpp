class Solution {
private:
    int buf[50001];
    
public:
    void mergesort(vector<int>& nums, int start, int finish){
        if(start==finish) return;
        int mid = (start+finish)/2;
        mergesort(nums,start,mid);
        mergesort(nums,mid+1,finish);
        
        int i=start,j=mid+1,k=start;
        //printf("i = %d j = %d  start = %d finish = %d\n",i,j,start,finish);
        while(i<=mid && j<=finish){
            if(nums[i]<nums[j]) buf[k++]=nums[i++];
            else buf[k++]=nums[j++];
        }
        printf("i = %d j = %d  start = %d finish = %d\n",i,j,start,finish);
        while(i<=mid) buf[k++]=nums[i++];
        while(j<=finish) buf[k++]=nums[j++];
        
        for(int p=start; p<=finish; p++){
            nums[p]=buf[p];
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0, nums.size()-1);
        return nums;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int num=0;
        for(vector<int>::iterator it=nums.begin(); it!=nums.end(); it++){
            for(vector<int>::iterator it2 = it+1; it2!=nums.end(); it2++){
                num = *it+*it2;
                if(num==target){
                    ans.push_back(distance(nums.begin(), it));
                    ans.push_back(distance(nums.begin(), it2));
                }
            }
        }
        return ans;
    }
};
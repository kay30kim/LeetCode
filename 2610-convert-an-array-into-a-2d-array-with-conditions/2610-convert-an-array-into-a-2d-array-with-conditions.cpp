class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        // 1) find duplicate
        vector<int> freq(nums.size() + 1);
        vector<vector<int>> ans;
        
        // 2) seperate them with frequency;
        for (auto num : nums) {
            if (freq[num] >= ans.size())
                ans.push_back(vector<int>()); // = ans.push_back({});
            ans[freq[num]].push_back(num);
            freq[num]++;
        }
        
        return ans;
    }
};
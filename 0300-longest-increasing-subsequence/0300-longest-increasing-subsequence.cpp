class Solution {
public:
    int lower_bound(vector<int>& arr, int num) {
        int left = 0, right = arr.size() - 1;
        while (left < right) { // lower_bound에서는 =이 없다?
            int mid = (left + right) / 2;
            if (arr[mid] > num)
                right = mid;
            else if (arr[mid] < num)
                left = mid + 1;
            else
                return mid;
        }
        // while (left <= right) { // lower_bound에서는 =이 없다?
        //     int mid = (left + right) / 2;
        //     if (arr[mid] > num)
        //         right = mid - 1;
        //     else if (arr[mid] < num)
        //         left = mid + 1;
        //     else
        //         return mid;
        // }
        return left;
    }
    int lengthOfLIS(vector<int>& nums) {
        // Approach 2) Binary Search
        vector<int> arr;
        arr.push_back(nums[0]);
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > arr[arr.size() - 1])
                arr.push_back(nums[i]);
            else {
                int j = lower_bound(arr, nums[i]);
                arr[j] = nums[i];
            }
        }
        return arr.size();
        /* 1) Approach 1) DP -> O(N)
        vector<int> dp(nums.size(), 1);
        int ans = 1;
        for (int i = 1; i < nums.size(); i++)
            for (int j = 0 ; j < i; j++) {
                if (nums[i] > nums[j]) 
                    dp[i] = max(dp[i], dp[j] + 1);
                ans = max(ans, dp[i]);
            }
        
        return ans; */
    }
};
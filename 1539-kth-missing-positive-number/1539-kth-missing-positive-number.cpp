class Solution {
public:
    int findKthPositive(vector<int>& a, int k) {
        int n = a.size();
        int low = 0, high = n - 1;
        
        while(low <= high) {
            int mid = (low + high) >> 1;
            if(a[mid] - mid - 1 < k) low = mid + 1;
            else high = mid - 1;
        }

        return low + k;
    }
};
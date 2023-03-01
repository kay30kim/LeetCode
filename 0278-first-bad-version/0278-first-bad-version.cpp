// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
private:
    int ans=0;
public:
    void binarySearch(int left, int right){
        int mid = left + (right-left)/2;
        if(isBadVersion(mid)) {
            ans=mid; 
            if(left!=right) binarySearch(left,mid);
        }
        else if(left!=right) binarySearch(mid+1,right);
    }
    int firstBadVersion(int n) {
        binarySearch(1,n);
        return ans;
    }
};
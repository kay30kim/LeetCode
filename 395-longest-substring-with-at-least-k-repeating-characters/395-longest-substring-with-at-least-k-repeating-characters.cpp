class Solution {
private:
    string S;
    int K;
    int lenLongestSubstring(int start, int end){
        if (start>end || end<start) return 0;
        if (start==end) return K==1 ? 1 : 0;
        int nChar[27]={0,};
        for(int i=start; i<=end; i++){
            nChar[S[i]-'a']++;
        }
        int mid=-1;
        for(int i=start; i<=end; i++){
            if(nChar[S[i]-'a'] < K){
                mid = i;
                break;
            }
        }
        if(mid==-1) return (end-start+1) >= K ? (end-start+1) : 0;
        return max(lenLongestSubstring(start,mid-1),lenLongestSubstring(mid+1,end));
    }
public:
    int longestSubstring(string s, int k) {
        S = s;
        K = k;
        return lenLongestSubstring(0,s.size()-1);
    }
};
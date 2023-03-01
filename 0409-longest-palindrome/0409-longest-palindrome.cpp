class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> hash;
        int ans=0, odd=0;
        for(auto c:s){
            hash[c]++;
        }
        for(auto c:hash){
            //printf("%c %d\n",c.first,c.second);
            ans += c.second/2*2;
            //printf("%d\n",ans);
            if(c.second%2==1 && odd==0) odd++;
        }
        return ans+odd;
    }
};
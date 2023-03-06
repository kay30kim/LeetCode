class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> hash;
        int pleft=0, pright=0, ans=0, count=1;
        hash[s[pright]]++;
        while(pright+1<s.size()){
            hash[s[++pright]]++;
            count = max(count,hash[s[pright]]);
           // printf("count = %d  %d %c\n",count, hash[s[pright]], s[pright]);
            //printf("%d\n",pright+1-pleft-count);
            if(pright+1-pleft-count > k){
                hash[s[pleft]]--;
                pleft++;
            }
            if(ans<pright-pleft+1) ans = pright-pleft+1;
        }
        return ans;
    }
};
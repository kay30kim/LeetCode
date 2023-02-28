// 1) Brute force
// 2) recursive (divide conquer)
// 3) two pointers 

class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int j=0, ans=0;
        for(int i=0; s[i]; i++){
            for(;t[j];j++){
                //printf("%c %c\n",s[i],t[j]);
                if(s[i]==t[j]){
                    //printf("%c %c\n",s[i],t[j]);
                    ans++;
                    j++;
                    break;
                }
            }
            //printf("%d\n",ans);
        }
        
        return s.size() == ans;
    }
};
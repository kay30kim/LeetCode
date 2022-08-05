class Solution2 {
private:
    int nChar[27];
    int num;
public:
    int numUniqChar(string s) {
        num = 0;
        for(int i=0; i<s.length(); i++){
            if(nChar[s[i]-'a']==0){
                nChar[s[i]-'a']++;
                num++;
            }
        }
        return num;
    }
};
class Solution {
private:
    Solution2 fun;
    int nChar[27];
public:
    int longestSubstring(string s, int k) {
        // clear();
        int maxAlphabet = fun.numUniqChar(s), ans=0;
        for(int nAlphabet=1; nAlphabet<=maxAlphabet; nAlphabet++){
            clear();
            int len=0, nowNAlphabet = 0, p1=0, p2=0, sAlphabet = 0;
            while(p2 < s.size()){
                //if(nChar[s[p2]-'a'])
                if(nowNAlphabet<=nAlphabet){ // <
                    if(nChar[s[p2]-'a']==0)nowNAlphabet++;
                    nChar[s[p2]-'a']++;
                    if(nChar[s[p2]-'a']==k) sAlphabet++;
                    len++;
                    p2++;
                }else{
                    if(nChar[s[p1]-'a']==k) sAlphabet--;
                    nChar[s[p1]-'a']--;
                    if(nChar[s[p1]-'a']==0)nowNAlphabet--;
                    len--;
                    p1++;                    
                }
                if(nowNAlphabet == nAlphabet && nowNAlphabet == sAlphabet)
                    ans = max(len,ans);
            }
        }
        return ans;
    }
    void clear(){
        for(int i=0 ; i<27; i++){
            nChar[i] = 0;
        }
    }
};

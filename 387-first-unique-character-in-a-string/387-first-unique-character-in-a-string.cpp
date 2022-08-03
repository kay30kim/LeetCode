class Solution {
private:
    int nChar[27];
public:
    int firstUniqChar(string s) {
        for(int i=0; i<s.size(); i++){
            nChar[s[i]-'a']++;
        }
        for(int i=0; i<s.length(); i++){
            if(nChar[s[i]-'a']==1){
                return i;
            }
        }
        return -1;
    }
};
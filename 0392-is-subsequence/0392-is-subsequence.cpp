// 1) Brute force O(n) n = max(s.size(),t.size()) // O(N) = s.size() + t.size()
// 2) recursive (divide conquer) O() // O()
// 3) two pointers // 

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int pleft=0, pright =0;
        while(pleft<s.length() && pright<t.length()){
            if(s[pleft] == t[pright]){
                pleft++;
            }
            pright++;
        }
        return pleft==s.length();
    }
}; 
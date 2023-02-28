// 1) Brute force O(n) n = max(s.size(),t.size()) // O(N) = s.size() + t.size()
// 2) recursive (divide conquer)
// 3) two pointers 

class Solution {
public:
    bool tailRecursion(string s, string t, int left, int right){
        if(left==s.length()) return true;
        if(right==t.length()) return false;
        
        if(s[left]==t[right]) left++;
        right++;
        
        return tailRecursion(s,t,left,right);
    }
    
    bool isSubsequence(string s, string t) {
        return tailRecursion(s,t,0,0);
    }
}; 
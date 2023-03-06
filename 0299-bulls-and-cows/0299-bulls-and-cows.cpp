class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls=0, cows=0;
        unordered_map<char,int> hash;
        for(int i=0; i<secret.size(); i++){
            hash[secret[i]]++;
        }
        for(int i=0; i<guess.size(); i++){
            if(secret[i]==guess[i]) {
                bulls++;
                hash[guess[i]]--;
            }
        }
        for(int i=0; i<guess.size(); i++){
            if(secret[i]!=guess[i] && hash[guess[i]]!=0){
                cows++;
                hash[guess[i]]--;
               // printf(">%c %d  %d\n",guess[i], cows,hash[guess[i]]);
            }
        }
        string ans = to_string(bulls)+'A'+to_string(cows)+'B';
        return ans;
    }
};
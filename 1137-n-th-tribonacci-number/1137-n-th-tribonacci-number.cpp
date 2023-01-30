int flag=1;
int pibo[38];
class Solution {
public:
    int tribonacci(int n) {
        if(flag){
            flag = 0;
            pibo[1] = 1;
            pibo[2] = 1;
            for(int i=3; i<38; i++){
                pibo[i] = pibo[i-1] + pibo[i-2] + pibo[i-3];
            }
        }
        return pibo[n];
    }
};
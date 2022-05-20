class Solution {
private:
    unsigned int arr[3]={1,10001,20001};
public:
    bool canTransform(string start, string end) {
        unsigned int sNum=0, eNum=0;
        for(int i=0; start[i]; i++){
            if(start[i]=='L'){
                sNum+=arr[0];
            }else if(start[i] =='R'){
                sNum+=arr[1];
            }else{
                sNum+=arr[2];
            }
        }
        for(int i=0; end[i]; i++){
            if(end[i]=='L'){
                eNum+=arr[0];
            }else if(end[i] =='R'){
                eNum+=arr[1];
            }else{
                eNum+=arr[2];
            }
        }
        if(sNum==eNum) {
// skip 'X', make sure start[i] and end[j] is the same
// 'R' position in start is smaller than end
// 'L' position in start is larger than end
            int i=0, j=0;
            while(i<start.size() && j<end.size()) {

                while(start[i]=='X') i++;
                while(end[j]=='X') j++;

                if(start[i]!=end[j]) return false;
                if(start[i]=='R' && i>j) return false;
                if(start[i]=='L' && i<j) return false;
                i++; j++;
            }
            return true;
        }
        else return false;
    }
};
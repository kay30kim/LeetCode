class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int i=num.size()-1;
        int cy=0;
        while(k>0 || cy>0)
        {
            int digit=k%10;
            k=k/10;
            int sum=digit+cy;

            if(i>=0)    
                sum+=num[i];

            int d=sum%10;

            if(i>=0)
                num[i]=d;
            else
                num.insert(num.begin(), d);
                
            sum=sum/10;
            cy=sum;
            if(i>=0)
                i--;
        }
        if(cy)
            num.insert(num.begin(), cy);
        return num;
    }
};
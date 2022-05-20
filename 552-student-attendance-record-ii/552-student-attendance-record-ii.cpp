class Solution {
private:
    int A[100001], P[100001], L[100001];
    const int m = 1000000007;
public:
    // T(n) = P(n) + L(n) + A(n)
    // A(1) = P(1) = L(1) = 1  initiative value.
    // P(n) = P(n-1) + L(n-1) +A(n-1) n>2
    // L(n) = A(n - 1) + P(n - 1) + L(n-2) (= A(n - 2) + P(n - 2)), n ≥ 3
    // A(n) = noAP(n - 1) + noAL(n - 1), n ≥ 2.
    // noAP(n) = noAP(n - 1) + noAL(n - 1), n ≥ 2.
    // noAL(n) = noAP(n - 1) + noAP(n - 2), n ≥ 3.
    // => A(n) = A(n - 1) + A(n - 2) + A(n - 3), n ≥ 4.

    Solution(){
        P[0] = 1; L[0] = 1; L[1] = 3; A[0] = 1; A[1] = 2; A[2] = 4;
    }
    int checkRecord(int n) {
        for(int i=1; i<n; i++){
            A[i-1]%=m;
            P[i-1]%=m;
            L[i-1]%=m;
            
            P[i] = ((P[i-1] + A[i-1]) % m + L[i-1]) %m;
            if(i>1) L[i] = ((A[i-1]+P[i-1])%m + (A[i-2]+P[i-2])%m)%m;
            if(i>2) A[i] = ((A[i-1]+A[i-2])%m + A[i-3])%m;
        }
        return ((A[n-1]%m + P[n-1]%m)%m + L[n-1]%m)%m;
    }
};
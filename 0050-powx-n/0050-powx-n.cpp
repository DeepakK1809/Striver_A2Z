class Solution {
public:
    double Solve(double x,long long N){
        if(N==0)return 1;
        if(N<0)return Solve(1/x,(-1*N));
        if(N%2==1)return x*Solve(x*x,(N-1)/2);
        return Solve(x*x,N/2);
    }
    double myPow(double x, int n) {
        long long N=n;
        return Solve(x,N);
    }
};
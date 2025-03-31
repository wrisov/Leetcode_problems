class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        if(divisor == 1) return dividend;
        if(dividend == -1) return -dividend;
        int k=0;
        int f=1;
        if(dividend<0){
            f=f*-1;
        }
        if(divisor<0){
            f=f*-1;
        }
        long long a = abs((long long)divisor);
        long long b = abs((long long)dividend);
        for(long long i=a; i<=b; i=i+a){
            if(a>b)
            break;
            k++;
        }
        return k*f;
    }
};
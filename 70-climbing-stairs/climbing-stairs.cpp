class Solution {
public:
    int climbStairs(int n) {
        vector<int> sum(n+1);
        sum[0]=1;
        sum[1]=1;
        for(int i=2;i<=n;i++)
        {
            sum[i]=sum[i-1]+sum[i-2];
        }
        return sum[n];
    }
};
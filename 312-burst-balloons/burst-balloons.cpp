class Solution {
public:
    int dp[502][502];
    int f(vector<int>& a,int i,int j)
    {
        if(i+1==j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int res=0;
        for(int k=i+1;k<j;k++){
            res=max(res,(f(a,i,k)+f(a,k,j)+a[i]*a[j]*a[k]));
        }
        return dp[i][j]=res;
    }
    int maxCoins(vector<int>& nums) {
     nums.insert(nums.begin(),1);
     nums.insert(nums.end(),1);
        int n= nums.size();
        memset(dp,-1,sizeof(dp));
        return f(nums,0,n-1);
    }
};
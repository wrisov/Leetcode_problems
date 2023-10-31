class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n);
        dp[0]= 1;
        int ans=1;
        for(int i=1;i<n;i++){
            int c = INT_MIN;
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i])
                c=max(c,dp[j]);
            }
            dp[i]= c==INT_MIN ? 1 : c+1;
            ans=max(ans,dp[i]);
        }
        return ans;   
    }
};
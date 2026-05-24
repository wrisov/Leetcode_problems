class Solution {
public:
    int rec(int idx,vector<int>&dp,vector<int>&a,int d){
        if(idx>=a.size() || idx<=-1){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        dp[idx]=1;
        for(int i=1;i<=d&&idx+i<a.size();i++){
            if(a[idx]<=a[i+idx]){
                break;
            }
            dp[idx]=max(dp[idx],rec(i+idx,dp,a,d)+1);
        }
        for(int i=1;i<=d&&idx-i>=0;i++){
            if(a[idx]<=a[idx-i]){
                break;
            }
            dp[idx]=max(dp[idx],rec(idx-i,dp,a,d)+1);
        }
        return dp[idx];
        
    }
    int maxJumps(vector<int>& a, int d) {
        int n=a.size();
        vector<int>dp(n,-1);
        
        for(int i=0;i<n;i++){
            if(dp[i]==-1){
                cout<<i;
                rec(i,dp,a,d);
            }
        }
        
        return *max_element(dp.begin(),dp.end());
    }
};
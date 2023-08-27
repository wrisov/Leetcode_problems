class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefix(100000,0);
        vector<int> suffix(100000,0);
        prefix[0]=height[0];
        for(int i=1;i<height.size();i++){
            prefix[i]=max(height[i],prefix[i-1]);
        }
        int n = height.size();
        suffix[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=max(suffix[i+1],height[i]);
        }
        int ans =0;
        for(int i=0;i<n;i++){
         int t = min(prefix[i],suffix[i])-height[i];
         ans+=t;   
        }
        return ans;
    }
};
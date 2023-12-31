class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
      deque<pair<int,int>>dq;
      int ans=INT_MIN;
      for(int i=0;i<nums.size();i++){
        
        while(!dq.empty() && dq.front().first<i-k){
         dq.pop_front();
        } 
        if(!dq.empty()){
         nums[i] = max(nums[i],nums[i]+dq.front().second);
        }
         while(!dq.empty()&&nums[i]>=dq.back().second) dq.pop_back();
         dq.push_back({i,nums[i]});
         ans=max(ans,nums[i]);
        
      }
      
      return ans;
    }
};
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1)
        return true;
        if(nums[0]==0)
        return false;
        for(int i=1;i<nums.size();i++){
            nums[i]= max(nums[i]+i,nums[i-1]);
            if(nums[i]<=i && i<nums.size()-1)
            return false;
        }
        return true;
    }
};
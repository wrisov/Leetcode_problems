class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int m=0;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1; j<nums.size();j++){
                if(nums[i]<nums[j]){
                    m=max(m,(nums[j]-nums[i]));
                }
            }
        }
        if(m==0)
        return -1;
        return m;
    }
};
class Solution {
public:
    void seperateDigits(int n, vector<int> &ans)
    {
        vector<int> temp;
        while(n>0)
        {
            int rem = n%10;
            temp.push_back(rem);
            n = n/10;
        }
        
        for(int i = temp.size() -1 ; i>=0;i--)
        {
            ans.push_back(temp[i]);
        }
    }
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int i =0; i< nums.size(); i++)
        {
            seperateDigits(nums[i], ans);
        }
        return ans;
    }
};
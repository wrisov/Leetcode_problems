class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        vector<int> ans;
        deque<int> q;
        int n = nums.size();
        
        for(int i = 0; i < n; i++)
        {
            if(!q.empty() and (i - q.front() >= k)) q.pop_front();
            
            while(!q.empty() and nums[i] > nums[q.back()]) q.pop_back();
            
            q.push_back(i);
            
            if(i >= k - 1) ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};
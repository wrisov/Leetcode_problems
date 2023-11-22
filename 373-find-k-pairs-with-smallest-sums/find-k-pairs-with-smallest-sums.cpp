class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        for(int i=0; i<m && i<k; i++) pq.push({nums1[0] + nums2[i], {0, i}});

        vector<vector<int>> ans;
        while(ans.size() < k && pq.size()) {
            auto a = pq.top(); pq.pop();
            int i = a.second.first, j = a.second.second;

            ans.push_back({nums1[i], nums2[j]});

            if(i + 1 < n) pq.push({nums1[i + 1] + nums2[j], {i + 1, j}});
        }
        return ans;
    }
};
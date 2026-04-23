class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<long long>> mp;
        
        // Step 1: store indices
        for (long long i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        vector<long long> ans(nums.size(), 0);

        // Step 2: process each group
        for (auto &it : mp) {
            vector<long long> &v = it.second;
            int k = v.size();

            vector<long long> prefix(k, 0);
            prefix[0] = v[0];
            for (int i = 1; i < k; i++) {
                prefix[i] = prefix[i - 1] + v[i];
            }

            long long totalSum = prefix[k - 1];

            for (int j = 0; j < k; j++) {
                long long left = v[j] * j - (j > 0 ? prefix[j - 1] : 0);
                long long right = (totalSum - prefix[j]) - (k - j - 1) * v[j];

                ans[v[j]] = left + right;
            }
        }

        return ans;
    }
};
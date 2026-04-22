class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> res;
        int current = 0;

        for (int bit : nums) {
            current = (current * 2 + bit) % 5;
            res.push_back(current == 0);
        }

        return res;
    }
};
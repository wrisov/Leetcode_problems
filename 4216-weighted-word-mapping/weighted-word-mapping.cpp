class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";

        for (string &w : words) {
            int sum = 0;

            for (char c : w) {
                sum += weights[c - 'a'];
            }

            int r = sum % 26;

            char mapped = 'z' - r;

            ans.push_back(mapped);
        }

        return ans;     
    }
};
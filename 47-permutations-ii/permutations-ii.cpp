class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> permutations;
        unordered_map<int, int> frequencyMap;

        // Count frequency of each number
        for (int num : nums) {
            frequencyMap[num]++;
        }

        vector<int> currentPermutation;
        generatePermutations(nums.size(), frequencyMap, currentPermutation, permutations);
        return permutations;
    }

private:
    void generatePermutations(int targetSize,
                              unordered_map<int, int>& frequencyMap,
                              vector<int>& currentPermutation,
                              vector<vector<int>>& permutations) {
        // If the current permutation is complete, add it to the result
        if (currentPermutation.size() == targetSize) {
            permutations.push_back(currentPermutation);
            return;
        }

        // Iterate over the frequency map
        for (auto& [num, count] : frequencyMap) {
            if (count == 0) continue;

            // Choose the number
            currentPermutation.push_back(num);
            frequencyMap[num]--;

            // Recurse
            generatePermutations(targetSize, frequencyMap, currentPermutation, permutations);

            // Backtrack
            currentPermutation.pop_back();
            frequencyMap[num]++;
        }
    }
};
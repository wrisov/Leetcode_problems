class Solution {
public:
    std::vector<int> findIntersectionValues(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::set<int> set1(nums1.begin(), nums1.end());
        std::set<int> set2(nums2.begin(), nums2.end());

        int count1 = 0;
        for (int num : nums1) {
            if (set2.count(num)) {
                count1++;
            }
        }

        int count2 = 0;
        for (int num : nums2) {
            if (set1.count(num)) {
                count2++;
            }
        }

        return {count1, count2};
    }
};
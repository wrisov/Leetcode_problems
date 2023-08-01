class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      if(nums.empty()) return 0;
      set<int> s;
      for (auto n: nums){
          s.insert(n);
      }
      
     auto fast = s.begin();
     fast++;
     auto slow = s.begin();
     int currLen = 1;
     int maxLen = 1;
      for (; fast != s.end(); fast++, slow++){
          if(*fast ==*slow + 1){
              currLen++;
          } else {
              maxLen = max(maxLen, currLen);
              currLen = 1;
          }
      }
      return max(maxLen, currLen);
    }
};
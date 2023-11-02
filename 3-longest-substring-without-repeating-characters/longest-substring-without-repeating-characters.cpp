class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start,end =0;
        int maxS = 0;
        unordered_set<char> uniqueChars;
        while(start<s.size()){
            auto it = uniqueChars.find(s[start]);
            if(it == uniqueChars.end()){
                maxS = max(maxS, start-end+1);
                uniqueChars.insert(s[start]);
                start++;
            } else {
                uniqueChars.erase(s[end]);
                end++;
            }
        }
        return maxS;
    }
};
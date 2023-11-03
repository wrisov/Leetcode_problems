class Solution {
public:
    int longestSubstring(string s, int k) {
        return helper(s, k, 0, s.size());
    }

    int helper(string s, int k, int start, int end){
        if(end-start<k)
        return 0;
        vector<int> count(26,0);
        for(int i=start; i<end;i++){
            count[s[i]-'a']++;
        }

        for(int i=start; i<end;i++){
            if(count[s[i]-'a']<k){
                int j=i+1;
                while(j<end && count[s[j]-'a']<k){
                    j++;
                }
                return max(helper(s,k,start,i), helper(s,k,j,end));
            }
        }
        return end-start;
    }
};
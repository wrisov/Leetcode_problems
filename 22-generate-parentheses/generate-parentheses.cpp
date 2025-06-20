class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
    void backtrack(vector<string>& result, string cur, int open, int close, int n){
        if(open == n && close == n){
            result.push_back(cur);
            return;
        }
        if(open <n){
            backtrack(result, cur+"(", open+1, close, n);
        }
        if(close<open){
            backtrack(result,cur+")", open, close+1, n);
        }
    }
};
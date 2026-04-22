class Solution {
public:
    bool checkMatch(string a, string b){
        int n=a.length();
        int s=0;
        for(int i=0;i<n;i++){
            if(a[i]!=b[i])
            s++;
        }
        if(s<=2)
        return true;
        return false;
    }

    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for(int i=0;i<queries.size();i++){
            for(int j=0;j<dictionary.size();j++){
                if(checkMatch(queries[i],dictionary[j])){
                ans.push_back(queries[i]);
                break;
                }
            }
        }
        return ans;    
    }
};
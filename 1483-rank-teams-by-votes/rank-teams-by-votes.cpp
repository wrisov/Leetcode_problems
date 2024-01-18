class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int m = votes[0].size();
        vector<vector<int>> mp(26,vector<int>(m,0));
        for(int i=0;i<votes.size();i++){
            string vote = votes[i];
            for(int j=0;j<vote.length();j++){
                mp[vote[j]-'A'][j]++; 
            }
        }
        vector<pair<vector<int>,char>> table(26);
        for(int i=0;i<26;i++){
            table[i]={mp[i],(i+'A')};
        }
        sort(table.begin(),table.end(),[](pair<vector<int>,char>& a, pair<vector<int>,char>& b){
            return (a.first > b.first) || (a.first == b.first && a.second < b.second);
        });

        string ans ="";
        for(int i=0;i<min(26,m);i++){
            ans+= table[i].second;
        }
        return ans;
    }
};
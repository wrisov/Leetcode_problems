class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        int mx=0;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
            mx = max(mx, mp[tasks[i]]);
        }
        int ans = (mx-1)*(n+1);
        for(auto it: mp){
            if(it.second == mx)
            ans++;
        }
        return max(ans, (int)tasks.size());
    }
};
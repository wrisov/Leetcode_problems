class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freq;
        int maxT=0;
        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]]++;
            maxT = max(maxT, freq[tasks[i]]);
        }
        int total = (maxT-1)*(n+1);
        for(auto it: freq){
            if(it.second == maxT)
            total++;
        }
        return max(total, (int)tasks.size());
    }
};
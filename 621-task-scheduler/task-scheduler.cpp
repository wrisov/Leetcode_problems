class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
     unordered_map<char,int> mp;
        int count=0;
        for(auto it:tasks)
        {
            mp[it]++;
            count=max(count,mp[it]);
        }
        int ans=(count-1)*n+count;
        int no_with_max=1;
        for(auto it:mp)
        {
            if(it.second==count)
            {
                ans++;
                no_with_max++;
            }
            
        }
        int fin_ans;
        if(no_with_max>1) fin_ans=max((int)tasks.size(),ans-1);
        else fin_ans= max((int)tasks.size(),ans); 
        return fin_ans;   
    }
};
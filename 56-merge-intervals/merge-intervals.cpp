class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int x = intervals[0][0];
        int y = intervals[0][1];
        vector<vector<int>> v;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=x && intervals[i][0]<=y){
                x = min(intervals[i][0],x);
                y = max(intervals[i][1],y);
            }
            else{
                v.push_back({x,y});
                x=intervals[i][0];
                y=intervals[i][1];
            }
        }
        v.push_back({x,y});
        return v;
    }
};
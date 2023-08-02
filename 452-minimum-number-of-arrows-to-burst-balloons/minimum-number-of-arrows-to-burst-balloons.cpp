class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
                 int breakpoint=points[0][1];
                 int ans=0;
         for(auto it : points){
              if(it[0]<=breakpoint){
                   breakpoint=min(it[1],breakpoint);
              }
              else{
                  ans++;
                  breakpoint=it[1];
              }
         }
         ans++;
         return ans;
        
    }
};
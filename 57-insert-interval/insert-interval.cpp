class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
         vector<vector<int>> finalResult;
        int i = 0, n = intervals.size();
        
        /**
        Step1 : add all the intervals in finalResult if it does not
        overlap with the newInterval
        **/
        while(i < n && intervals[i][1] < newInterval[0]) finalResult.push_back(intervals[i++]);
        
        /**
        Step2 : when we are out of previous while loop, so we know what we got our overlap point
        now its time to insert newInterval in the overlap point
        **/
        vector<int>tempInterval = newInterval;
       
        //once we are out from this while we will know the exact value need to insert after overlap
        while(i < n && intervals[i][0] <= newInterval[1])
        {
            tempInterval[0] = min(tempInterval[0], intervals[i][0]);
            tempInterval[1] = max(tempInterval[1], intervals[i++][1]);
        }
       finalResult.push_back(tempInterval);
        
        /**
        Step3 : Now just insert rest of the intervals into result array
        **/ 
        
        while(i<n) finalResult.push_back(intervals[i++]);
    
    return finalResult;  
    }
};
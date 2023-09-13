class Solution {
private:
    bool binarySearch(vector<int>&arr,int target){
        int low = 0;
        int high = arr.size()-1;
        while(high-low>=0){
            int mid = (high+low)/2;
            if(arr[mid]>target){
                high = mid-1;
            }
            else if(arr[mid]<target)    low = mid+1;
            else return true;
        }
        return false;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        bool ch = binarySearch(nums,target);
        if(!ch) return {-1,-1};
        int val1 = lower_bound(nums.begin() , nums.end() , target)-nums.begin();
        int val2 = upper_bound(nums.begin() , nums.end() , target)-nums.begin();
        return {val1,val2-1};   // Our upper bounds go one index further so we subtract 1.
    }
};
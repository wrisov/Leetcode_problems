class Solution {
public:
    int searchInsert(vector<int>& a, int t) {
       int l=0;
    int h=a.size()-1;
    while(l<=h)
    {
        int mid=l+(h-l)/2;
        if(a[mid]==t)
        {
            return mid;
        }
        else if(a[mid]>t)
        {
            h=mid-1;
        }
        else if(a[mid]<t)
        {
            l=mid+1;
        }
    }
    return l;
    }
};
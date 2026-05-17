class Solution {
public:

    bool dfs(vector<int>& arr, int idx, vector<bool>& vis) {

        // Out of bounds
        if(idx < 0 || idx >= arr.size() || vis[idx])
            return false;

        // Found zero
        if(arr[idx] == 0)
            return true;

        vis[idx] = true;

        // Jump forward or backward
        return dfs(arr, idx + arr[idx], vis) ||
               dfs(arr, idx - arr[idx], vis);
    }

    bool canReach(vector<int>& arr, int start) {
        vector<bool> vis(arr.size(), false);

        return dfs(arr, start, vis);
    }
};
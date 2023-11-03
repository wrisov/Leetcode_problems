class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<int>& vis, int& t, int& i){
        vis[i]=1;
        t++;
        for(int j=0;j<adj[i].size();j++){
            if(!vis[adj[i][j]]){
                dfs(adj, vis, t, adj[i][j]);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            long long int x = bombs[i][0];
            long long int y = bombs[i][1];
            long long int r = bombs[i][2];

            for(int j=0;j<n;j++){
                if(i!=j){
                long long int x1 = abs(x-bombs[j][0]);
                long long int y1 = abs(y-bombs[j][1]);
                if(x1*x1 + y1*y1 <= r*r)
                adj[i].push_back(j);
            }
            }
        }
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            vector<int> vis(n,0);
            int t=0;
            dfs(adj, vis, t, i);
            ans = max(ans,t);
        }

        return ans;
    }
};
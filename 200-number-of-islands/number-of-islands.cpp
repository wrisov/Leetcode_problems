class Solution {
public:
    int dfs(int i, int j, int m, int n, vector<vector<int>>& vis, vector<vector<char>>& grid){
        if(i>=0 && i<m && j>=0 && j<n && !vis[i][j] && grid[i][j]=='1'){
            vis[i][j]=1;
            dfs(i+1, j,m,n,vis, grid);
            dfs(i-1, j,m,n,vis, grid);
            dfs(i, j+1,m,n,vis, grid);
            dfs(i, j-1,m,n,vis, grid);   
            return 1;
        }
        return 0;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res+=dfs(i,j,m,n,vis,grid);
            }
        }
        return res;
    }
};
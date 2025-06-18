class Solution {
public:
    int dist[51][51], n;
    vector<vector<int>> height, add;
    bool check1(int i, int j) { return i >= 0 && i < n && j >= 0 && j < n; }
    void dijkstra(int x, int y) {
        dist[x][y] = height[x][y];
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            check;
        check.push({height[x][y], x, y});
        vector<int> a;
        while (!check.empty()) {
            a = check.top();
            check.pop();
            for (auto i : add) {
                int ii = i[0] + a[1], jj = i[1] + a[2];
                if (check1(ii, jj)) {
                    if(dist[ii][jj]>height[ii][jj]&&dist[a[1]][a[2]]<dist[ii][jj]){
                        dist[ii][jj]=max(height[ii][jj],dist[a[1]][a[2]]);
                        check.push({dist[ii][jj], ii, jj});
                    }
                }
            }
        }
    }
    int swimInWater(vector<vector<int>>& grid) {
        height = grid;
        n = grid.size();
        add = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                dist[i][j] = 1e9;
        }
        dijkstra(0, 0);
        return dist[n - 1][n - 1];
    }
};
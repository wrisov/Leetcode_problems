class Solution {
public:
    static constexpr long long MOD = 1e9 + 7;

    vector<vector<int>> up;
    vector<int> depth;
    vector<long long> pow2;
    int LOG;

    void dfs(int node, int parent,
             vector<vector<int>>& g) {

        up[0][node] = parent;

        for (int nxt : g[node]) {
            if (nxt == parent) continue;

            depth[nxt] = depth[node] + 1;
            dfs(nxt, node, g);
        }
    }

    int lca(int u, int v) {

        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int j = 0; j < LOG; j++) {
            if (diff & (1 << j))
                u = up[j][u];
        }

        if (u == v) return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[j][u] != up[j][v]) {
                u = up[j][u];
                v = up[j][v];
            }
        }

        return up[0][u];
    }

    vector<int> assignEdgeWeights(
        vector<vector<int>>& edges,
        vector<vector<int>>& queries) {

        int n = edges.size() + 1;

        vector<vector<int>> g(n + 1);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            g[u].push_back(v);
            g[v].push_back(u);
        }

        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        up.assign(LOG, vector<int>(n + 1));
        depth.assign(n + 1, 0);

        dfs(1, 1, g);

        for (int j = 1; j < LOG; j++) {
            for (int i = 1; i <= n; i++) {
                up[j][i] =
                    up[j - 1][ up[j - 1][i] ];
            }
        }

        pow2.assign(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {

            int u = q[0];
            int v = q[1];

            int w = lca(u, v);

            int len =
                depth[u] +
                depth[v] -
                2 * depth[w];

            if (len == 0)
                ans.push_back(0);
            else
                ans.push_back(pow2[len - 1]);
        }

        return ans;
    }
};
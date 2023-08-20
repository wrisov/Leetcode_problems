class Solution {
public:
    vector<int> adj[30007];
    vector<int> sub;
    vector<int> dep;
    vector<int> sum;
    int n;
    void dfs(int u, int par=-1){
        sub[u]=1;
        for(auto x: adj[u]){
            if(x == par){
                continue;
            }
            dep[x] = dep[u] + 1;
            dfs(x, u);
            sub[u]+=sub[x];
        }
    }
    void dfs2(int u, int par=-1){
        for(auto x:adj[u]){
            if(x==par){
                continue;
            }
            sum[x]=sum[u]-sub[x]+(n-sub[x]);
            dfs2(x,u);
        }
    }
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        n=N;
        sub.resize(n+1);
        dep.resize(n+1);
        sum.resize(n);
        for(int i=0;i<edges.size();i++){
            int a = edges[i][0];
            int b = edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(0);
        for(int i=0;i<n;i++){
            sum[0]+=dep[i];
        }
        dfs2(0);
        return sum;
    }
};
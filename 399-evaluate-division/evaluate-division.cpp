class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
         unordered_map<string, vector<pair<string, double>>> umap;
        for (int i = 0; i < equations.size(); i++) {
            vector<string> eqn = equations[i];
            umap[eqn[0]].push_back({eqn[1], values[i]});
            umap[eqn[1]].push_back({eqn[0], 1.0 / values[i]});
        }
        vector<double> result;
        for (auto & query : queries) {
            string start = query[0], end = query[1];
            if (!umap.count(start) or !umap.count(end)) {  // if any of the query values is not sotred in our adjacency list then return -1.0
                result.push_back(-1.0);
                continue;
            }
            // perform BFS from starting point.
            queue<pair<string, double>> q;
            unordered_set<string> seen;
            q.push({start, 1});
            while (!q.empty()) {
                pair<string, double> p = q.front(); seen.insert(p.first);
                if (p.first == end) {   // arrived end.
                    result.push_back(p.second);
                    break;
                }
                q.pop(); // pop only if we haven't found a path.
                for (auto var : umap[p.first]) {
                    if (!seen.count(var.first)) q.push({var.first, p.second * var.second});
                }
            }
            if (q.empty()) result.push_back(-1.0); // if queue is empty then we didn't find a path.
        }
        return result;

    }
};
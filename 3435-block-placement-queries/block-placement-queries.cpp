class SegmentTree {
public:
    int n;
    vector<int> tree;

    SegmentTree(int n) : n(n) {
        tree.resize(4 * n, 0);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(2 * node, l, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, r, idx, val);

        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;

        if (ql <= l && r <= qr)
            return tree[node];

        int mid = (l + r) / 2;

        return max(
            query(2 * node, l, mid, ql, qr),
            query(2 * node + 1, mid + 1, r, ql, qr)
        );
    }

    int query(int l, int r) {
        if (l > r) return 0;
        return query(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {

        vector<int> coords = {0};

        for (auto &q : queries) {
            coords.push_back(q[1]);
        }

        sort(coords.begin(), coords.end());
        coords.erase(unique(coords.begin(), coords.end()), coords.end());

        int m = coords.size();

        auto getIdx = [&](int x) {
            return lower_bound(coords.begin(), coords.end(), x) - coords.begin();
        };

        SegmentTree seg(m);

        set<int> obstacles;
        obstacles.insert(0);

        vector<bool> ans;

        for (auto &q : queries) {

            if (q[0] == 1) {

                int x = q[1];

                auto itR = obstacles.upper_bound(x);
                auto itL = prev(itR);

                int L = *itL;
                int R = (itR == obstacles.end() ? -1 : *itR);

                obstacles.insert(x);

                seg.update(getIdx(x), x - L);

                if (R != -1) {
                    seg.update(getIdx(R), R - x);
                }

            } else {

                int x = q[1];
                int sz = q[2];

                auto it = obstacles.upper_bound(x);

                int p = *prev(it);

                int best = seg.query(0, getIdx(p));

                best = max(best, x - p);

                ans.push_back(best >= sz);
            }
        }

        return ans;
    }
};
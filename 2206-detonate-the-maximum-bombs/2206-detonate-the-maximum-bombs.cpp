class Solution {
public:
    vector<vector<int>> G;
    vector<int> used;
    int tag = 0;

    int bfs(int start) {
        int cnt = 0;
        queue<int> q{{start}};
        used[start] = tag;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cnt++;

            for (int v : G[u]) {
                if (used[v] != tag) {
                    used[v] = tag;
                    q.push(v);
                }
            }
        }

        return cnt;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        G.resize(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                long long x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
                long long x2 = bombs[j][0], y2 = bombs[j][1];
                long long dis = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
                if (dis <= r1 * r1) {
                    G[i].emplace_back(j);
                }
            }
        }

        int maxx = 0;
        used.assign(n, 0);

        for (int i = 0; i < n; i++) {
            tag++;
            maxx = max(maxx, bfs(i));
        }

        return maxx;
    }
};
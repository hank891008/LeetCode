class Solution {
public:
    int fa[100000 + 5];
    void init(int n) {
        for(int i = 0; i < n; i++) {
            fa[i] = i;
        }
    }
    int findr(int x) {
        return x == fa[x] ? fa[x] : fa[x] = findr(fa[x]);
    }
    void unite(int x, int y) {
        x = findr(x);
        y = findr(y);
        if(x == y) {
            return;
        }
        fa[x] = y;
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        init(n);
        for(auto pair: pairs) {
            unite(pair[0], pair[1]);
        }
        vector<vector<int>> arr(n);
        for(int i = 0; i < s.size(); i++) {
            arr[findr(i)].push_back(i);
        }
        for(auto ch: arr) {
            string ss = "";
            for(auto idx: ch) {
                ss += s[idx];
            }
            sort(ss.begin(), ss.end());
            for(int i = 0; i < ch.size(); i++) {
                s[ch[i]] = ss[i];
            }
        }
        return s;

    }
};
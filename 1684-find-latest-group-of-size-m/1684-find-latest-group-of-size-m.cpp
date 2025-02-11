class Solution {
public:
    vector<int> fa, size, count;
    void init(int n){
        fa.resize(n, -1);
        size.resize(n, 0);
        count.resize(n + 1, 0);
    }
    void add(int x){
        fa[x] = x;
        size[x]++;
        count[1]++;
    }

    int findr(int x){
        return x == fa[x] ? fa[x] : fa[x] = findr(fa[x]);
    }

    void unite(int x, int y){
        x = findr(x);
        y = findr(y);
        if(x == y){
            return;
        }
        if(size[x] < size[y]){
            swap(x, y);
        }
        count[size[x]]--;
        count[size[y]]--;
        size[x] += size[y];
        fa[y] = x;
        count[size[x]]++;
    }

    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        init(n);
        vector<int> v(n, 0);

        int last = -1, step = 1;
        for(int i: arr){
            i--;
            v[i] = 1;
            add(i);
            if(i - 1 >= 0 && v[i - 1]){
                unite(i, i - 1);
            }
            if(i + 1 < n && v[i + 1]){
                unite(i, i + 1);
            }
            if(count[m]){
                last = step;
            }
            step++;
        }
        return last;
    }
};
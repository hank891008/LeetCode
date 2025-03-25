class Solution {
public:
    bool check(list<pair<int, int>> b){
        b.sort();
        int cnt = 0;
        int left_most = b.begin()->second;
        for(auto [l, r]: b){
            if(l >= left_most){
                cnt++;
            }
            left_most = max(left_most, r);
            if(cnt == 2){
                return true;
            }
        }
        return false;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        list<pair<int, int>> h, c;
        for(auto rec: rectangles){
            h.emplace_back(rec[0], rec[2]);
            c.emplace_back(rec[1], rec[3]);
        }
        return check(h) || check(c);
    }
};
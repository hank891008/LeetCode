class Solution {
public:
    static bool cmp(vector<int>a, vector<int>b){
        return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>>ans;
        int l = intervals[0][0], r = intervals[0][1]; 
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] >= l && intervals[i][0] <= r){
                    r = max(r, intervals[i][1]);
            }
            else{
                ans.emplace_back(vector<int>({l, r}));
                l = intervals[i][0];
                r = intervals[i][1];
            }
        }
        ans.emplace_back(vector<int>({l, r}));
        return ans;
    }
};
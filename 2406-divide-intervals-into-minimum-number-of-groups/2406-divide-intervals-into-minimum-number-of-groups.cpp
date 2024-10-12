class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](vector<int> x, vector<int> y){
           return x[0] < y[0];
        });
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < intervals.size(); i++){
            if(!pq.empty() && pq.top() < intervals[i][0]){
                pq.pop();
            }
            pq.emplace(intervals[i][1]);
        }
        return pq.size();
    }
};
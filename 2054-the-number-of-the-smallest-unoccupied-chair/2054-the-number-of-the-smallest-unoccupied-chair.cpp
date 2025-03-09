class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        map<vector<int>, int> m;
        for(int i = 0; i < times.size(); i++){
            m[times[i]] = i;
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq(times.begin(), times.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leave;
        priority_queue<int, vector<int>, greater<int>> can_use;
        for(int i = 0; i < times.size(); i++){
            can_use.emplace(i);
        }
        while(!pq.empty()){
            auto now = pq.top();    pq.pop();
            while(!leave.empty() && now[0] >= leave.top().first){
                can_use.emplace(leave.top().second);
                leave.pop();
            }
            int chair = can_use.top();  can_use.pop();
            if(m[now] == targetFriend){
                return chair;
            }
            leave.push({now[1], chair});
        }
        return -1;
    }
};
class Solution {
public:
    int ans = 16;
    void dfs(vector<int>& tasks, vector<int>& sessions, int i, int sessionTime){
        if(sessions.size() >= ans) return;
        if(i == tasks.size()){
            ans = sessions.size();
            return;
        }
        for(int j = 0; j < sessions.size(); j++){
            if(sessions[j] + tasks[i] <= sessionTime){
                sessions[j] += tasks[i];
                dfs(tasks, sessions, i + 1, sessionTime);
                sessions[j] -= tasks[i];
            }
        }
        sessions.emplace_back(tasks[i]);
        dfs(tasks, sessions, i + 1, sessionTime);
        sessions.pop_back();
    }
    int minSessions(vector<int>& tasks, int sessionTime) {
        vector<int> s;
        dfs(tasks, s, 0, sessionTime);
        return ans;
    }
};
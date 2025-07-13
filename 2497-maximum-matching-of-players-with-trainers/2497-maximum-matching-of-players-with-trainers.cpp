class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int ans = 0;
        for(int i = 0, j = 0; i < players.size() && j < trainers.size(); ){
            if(players[i] <= trainers[j]){
                ans++;
                i++;
            }
            j++;
        }
        return ans;
    }
};
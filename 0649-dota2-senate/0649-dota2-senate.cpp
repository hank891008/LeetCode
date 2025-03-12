class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> r, d;
        for(int i = 0; i < n; i++){
            (senate[i] == 'R') ? r.emplace(i) : d.emplace(i);
        }
        while(!r.empty() && !d.empty()){
            int rad = r.front();
            r.pop();
            int dir = d.front();
            d.pop();
            if(rad < dir){
                r.emplace(n++);
            }
            else{
                d.emplace(n++);
            }
        }
        return (!r.empty()) ? "Radiant" : "Dire";
    }
};
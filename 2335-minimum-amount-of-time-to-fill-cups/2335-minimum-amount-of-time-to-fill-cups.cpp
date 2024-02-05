class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        for(int i = 0; i < amount.size(); i++){
            if(amount[i] > 0){
                pq.emplace(amount[i]);
            }
        }
        int ans = 0;
        while(!pq.empty()){
            int a = pq.top();   pq.pop();
            if(!pq.empty()){
                int b = pq.top();   pq.pop();
                ans++;
                a--;
                b--;
                if(a > 0){
                    pq.emplace(a);
                }
                if(b > 0){
                    pq.emplace(b);
                }
            }
            else{
                a--;
                ans++;
                if(a > 0){
                    pq.emplace(a);
                }
            }
        }
        return ans;
    }
};
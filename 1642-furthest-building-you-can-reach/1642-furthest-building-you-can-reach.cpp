class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int> pq;
        for(int i = 0; i < n - 1; i++){
            int diff = heights[i + 1] - heights[i];
            if(diff > 0){
                bricks -= diff;
                pq.emplace(diff);
                if(bricks < 0){
                    bricks += pq.top();
                    pq.pop();
                    if(ladders > 0){
                        ladders--;
                    }
                    else{
                        return i;
                    }
                }
            }
        }
        return n - 1;
    }
};
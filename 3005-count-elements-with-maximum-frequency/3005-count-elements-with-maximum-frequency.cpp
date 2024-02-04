class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int>m;
        int maxx = 0;
        int cnt = 0;
        for(auto num: nums){
            m[num]++;
            if(maxx == m[num]){
                cnt++;
            }
            else if(maxx < m[num]){
                maxx = m[num];
                cnt = 1;
            }
        }
        return cnt * maxx;
        
    }
};
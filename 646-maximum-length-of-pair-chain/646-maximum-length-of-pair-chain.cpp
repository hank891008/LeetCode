class Solution {
public:
    struct item{
        int a, b;
        bool operator<(const item& rhs)const{
            return b < rhs.b;
        }
    };
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<item>v;
        for(int i = 0; i < pairs.size(); i++){
            v.push_back({pairs[i][0], pairs[i][1]});
        }
        sort(v.begin(), v.end());
        int r = v[0].b;
        int ans = 1;
        for(int i = 1; i < v.size(); i++){
            if(v[i].a > r){
                ans++;
                r = v[i].b;
            }
        }
        return ans;
    }
};
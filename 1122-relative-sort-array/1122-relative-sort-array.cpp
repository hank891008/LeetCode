class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> m;
        for(auto a: arr1){
            m[a]++;
        }
        vector<int> ans;
        for(int i = 0; i < arr2.size(); i++){
            if(m.count(arr2[i])){
                fill_n(back_inserter(ans), m[arr2[i]], arr2[i]);
                m.erase(arr2[i]);
            }
        }
        for(auto [k, v]: m){
            fill_n(back_inserter(ans), v, k);
        }
        return ans;
    }
};
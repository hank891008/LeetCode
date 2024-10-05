class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, int> m;
        vector<int> copy = arr;
        sort(copy.begin(), copy.end());
        int ranking = 0;
        int prev = INT_MIN;
        for(int i = 0; i < copy.size(); i++){
            if(copy[i] > prev){
                ranking++;
                prev = copy[i];
            }
            m[copy[i]] = ranking;
        }
        for(int i = 0; i < arr.size(); i++){
            arr[i] = m[arr[i]];
        }
        return arr;
    }
};
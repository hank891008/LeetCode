class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        vector<int> prefix = nums;
        prefix.insert(prefix.begin(), 0);
        for(int i = 1; i < prefix.size(); i++){
            prefix[i] += prefix[i - 1];
        }
        prefix.push_back(0);
        for(int i = 1; i < prefix.size() - 1; i++){
            // cout << prefix[i - 1] << ' ' << prefix[prefix.size() - 2]<< '\n';
            if(prefix[i - 1] == prefix[prefix.size() - 2] - prefix[i]){
                return i - 1;
            }   
        }
        return -1;
    }
};
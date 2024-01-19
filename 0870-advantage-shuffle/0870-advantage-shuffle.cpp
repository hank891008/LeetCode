class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        map<int, int>m;
        
        for(int i = 0; i < n; i++){
            m[nums1[i]]++;
        }
        for(int i = 0; i < n; i++){
            auto it = m.upper_bound(nums2[i]);
            if(it == m.end()){
                it = m.begin();
            }
            nums1[i] = it->first;
            it->second--;
            if(it->second == 0){
                m.erase(it);
            }
        }
        return nums1;
    }
};
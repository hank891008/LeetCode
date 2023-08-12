class FindSumPairs {
public:
    vector<int>v1, v2;
    map<int, int>m;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) { 
        swap(v1, nums1);
        swap(v2, nums2);
        sort(v1.begin(), v1.end());
        for(auto n: v2){
            m[n]++;
        }
    }
    
    void add(int index, int val) {
        m[v2[index]]--;
        v2[index] += val;
        m[v2[index]]++;
    }
    
    int count(int tot) {
        int ret = 0;
        for(auto num1: v1){
            if(num1 >= tot){
                break;
            }
            if(m.count(tot - num1)){
                ret += m[tot - num1];
            }
        }
        return ret;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        bitset<55> a, b;
        vector<int> ans;
        for(int i = 0; i < n; i++){
            a.set(A[i]);
            b.set(B[i]);
            ans.emplace_back((a & b).count());
        }
        return ans;
    }
};
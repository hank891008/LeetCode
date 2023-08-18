class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int arr[edges.size() + 5];
        memset(arr, 0, sizeof(arr));
        for(int i = 0; i < edges.size(); i++){
            arr[edges[i][0]]++;
            arr[edges[i][1]]++;
            if(arr[edges[i][0]] == edges.size()){
                return edges[i][0];
            }
            if(arr[edges[i][1]] == edges.size()){
                return edges[i][1];
            }
        }
        return -1;
    }
};
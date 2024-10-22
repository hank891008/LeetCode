class Solution {
public:
    int compareVersion(string version1, string version2) {
        int cnt1 = count(version1.begin(), version1.end(), '.');
        int cnt2 = count(version2.begin(), version2.end(), '.');
        while(cnt1 != cnt2){
            if(cnt1 > cnt2){
                version2 += ".0";
                cnt2++;
            }
            else{
                version1 += ".0";
                cnt1++;
            }
        }
        version1 += ".";
        version2 += ".";
        while(version1.size() && version2.size()){
            int v1 = stoi(version1.substr(0, int(find(version1.begin(), version1.end(), '.') - version1.begin()) + 1));
            int v2 = stoi(version2.substr(0, int(find(version2.begin(), version2.end(), '.') - version2.begin()) + 1));
            if(v1 > v2){
                return 1;
            }
            else if(v1 < v2){
                return -1;
            }
            version1 = version1.substr(int(find(version1.begin(), version1.end(), '.') - version1.begin()) + 1);
            version2 = version2.substr(int(find(version2.begin(), version2.end(), '.') - version2.begin()) + 1);
        }
        return 0;
    }
};
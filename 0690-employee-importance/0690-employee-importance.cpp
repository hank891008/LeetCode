/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        Employee* root;
        map<int, Employee*> m;
        for(auto employee: employees){
            if(employee->id == id){
                root = employee;
            }
            m[employee->id] = employee;
        }
        int ans = 0;
        queue<Employee*> q;
        q.emplace(root);
        while(!q.empty()){
            Employee* now = q.front();  q.pop();
            ans += now->importance;
            for(auto next: now->subordinates){
                q.emplace(m[next]);
            }
        }
        return ans;
        
    }
};
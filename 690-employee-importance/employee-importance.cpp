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
        int s=0;
        unordered_map<int, Employee*> idMap;
        unordered_map<int, bool> visited;
        for(int i=0;i<employees.size();i++){
            idMap[employees[i]->id] = employees[i];
            visited[employees[i]->id] = false;
        }
        int n = employees.size();
        // vector<bool> visited(n, false);
        queue<int> q;
        q.push(id);
        visited[id]=true;
        while(!q.empty()){
            int j =q.front();
            q.pop();
            Employee* e = idMap[j];
            s=s+e->importance;
            for(int i=0;i<e->subordinates.size();i++){
                if(!visited[e->subordinates[i]])
                q.push(e->subordinates[i]);
            }
        }
        return s;
    }
};
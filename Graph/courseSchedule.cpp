#include <bits/stdc++.h>
using namespace std;
bool canFinish(int numCourses, vector<vector<int>>& dir) {
    vector<int> adj[numCourses];
    for(int i=0; i<dir.size(); i++)
        adj[dir[i][1]].push_back(dir[i][0]);
        
    vector<int> in(numCourses, 0);
    set<int> st;
    for(int i=0; i<dir.size(); i++){
        int num = dir[i][0];
        in[num]++;
        if(!st.count(num))
            st.insert(num);
    }
    queue<int> q;
    for(int i=0; i<numCourses; i++)
        if(in[i]==0)
            q.push(i);
        
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(auto x : adj[front]){
            in[x]--;
            if(in[x]==0){
                q.push(x);
                st.erase(x);
            }
        }
    }
    return st.empty();
}

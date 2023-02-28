#include <bits/stdc++.h>
using namespace std;
void BFS(vector<int> adj[], int s){
    set<int> st;
    queue<int> q;
    st.insert(s);
    q.push(s);

    while(!q.empty()){
        int front = q.front();
        q.pop();
        cout<<front<<' ';
        for(int i : adj[front]){
            if(!st.count(i)){
                st.insert(i);
                q.push(i);
            }
        }
    }
}
void addEdge(vector<int> adj[], int i, int j){
    adj[i].push_back(j);
    adj[j].push_back(i);
}
int main(){
    int s = 6;
    vector<int> adj[s];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 5);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 5);
    addEdge(adj, 2, 4);
    addEdge(adj, 4, 5);

    BFS(adj, 0);

    return 0;
}
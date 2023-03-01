#include <bits/stdc++.h>
#include "addEdge.cpp"
using namespace std;
void BFS(vector<int> adj[], int s, vector<bool>& visited){
    set<int> st;
    queue<int> q;
    st.insert(s);
    visited[s] = true;
    q.push(s);

    while(!q.empty()){
        int front = q.front();
        q.pop();
        cout<<front<<' ';
        for(int i : adj[front]){
            if(!st.count(i)){
                st.insert(i);
                visited[i] = true;
                q.push(i);
            }
        }
    }
}
void doVisit(vector<int> adj[], int size){
    int count = 0;
    vector<bool> visited(size, false);
    for(int i=0; i<size; i++){
        if(!visited[i]){ 
            BFS(adj, i, visited);
            count++;
        }
    }
    cout<<"\nNo of disconnected pairs are: "<<count;
}
int main(){
    int v = 9;
    vector<int> adj[v];
    add(adj, 0, 1);
    add(adj, 0, 2);
    add(adj, 1, 2);
    add(adj, 4, 3);
    add(adj, 6, 5);
    add(adj, 5, 7);
    add(adj, 7, 8);

    doVisit(adj, v);
    return 0;
}
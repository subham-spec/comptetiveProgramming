#include <bits/stdc++.h>
#include "addEdge.cpp"
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
int main(){
    int s = 6;
    vector<int> adj[s];
    add(adj, 0, 1);
    add(adj, 0, 2);
    add(adj, 0, 5);
    add(adj, 1, 3);
    add(adj, 3, 5);
    add(adj, 2, 4);
    add(adj, 4, 5);

    BFS(adj, 0);

    return 0;
}
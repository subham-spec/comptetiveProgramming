#include <bits/stdc++.h>
#include "addEdge.cpp"
using namespace std;
void doDFS(vector<int> adj[], int i, vector<bool>& vis){
    cout<<i<<' ';
    vis[i] = true;
    for(int s : adj[i]){
        if(!vis[s])
            doDFS(adj, s, vis);
    }
}
void dfs(vector<int> adj[], int s){
    vector<bool> vis(s, false);
    for(int i=0; i<s; i++){
        if(!vis[i])
            doDFS(adj, i, vis);
    }
}
int main(){
    int s = 6;
    vector<int> adj[s];
    add(adj, 0, 1);
    add(adj, 0, 2);
    add(adj, 1, 3);
    add(adj, 1, 4);
    add(adj, 2, 3);
    add(adj, 4, 5);

    dfs(adj, s);

    return 0;
}
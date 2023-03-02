#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[], int s , vector<bool>& visited){
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while(!q.empty()){
        int p = q.front();
        q.pop();
        cout<<p<<" ";
        for(auto x : adj[p]){
            if(visited[x]==false){
                visited[x]==true;
                q.push(x);
            }
        }
    }
}
void addEdges(vector<int>adj[], int u , int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
} 
int  Bfs(vector<int> adj[] , int v){
    vector<bool>visited(v+1,false);
    int count = 0;
    for(int i = 0 ; i<v ; i++){
        if(visited[i]==false){
            bfs(adj, i, visited);
            count++;
        }
    }
    return count;
}
int  main(){
    int v=5;
    vector<int>adj[v];
    addEdges(adj , 1, 0);
    addEdges(adj , 1, 2);
    addEdges(adj , 0, 1);
    addEdges(adj , 0, 2);
    addEdges(adj , 2, 1);
    addEdges(adj , 2, 0);
    Bfs(adj,v);
 }
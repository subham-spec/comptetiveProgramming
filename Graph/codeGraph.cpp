#include <bits/stdc++.h>
using namespace std;
void printGraph(vector<int> adj[]){
    for(int i=0; i<4; i++){
        for(auto j: adj[i])
            cout<<j<<' ';
        cout<<endl;
    }
}
void addEdge(vector<int> adj[], int i, int j){
    adj[i].push_back(j);
    adj[j].push_back(i);
}
int main(){
    int v = 4;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    
    printGraph(adj);
}
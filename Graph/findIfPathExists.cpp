#include <bits/stdc++.h>
#include "addEdge.cpp"
using namespace std;
void add(vector<int> adj[], int f, int s){
    adj[f].push_back(s);
    adj[s].push_back(f);
}
bool path_exists(vector<int> adj[], int source, int desti, int n){
    set<int> s;
    queue<int> q;
    s.insert(source);
    q.push(source);
        
    while(!q.empty()){
        int front = q.front();
        q.pop();
        if(front == desti)
            return true;
        for(int i : adj[front]){
            if(!s.count(i)){
                s.insert(i);
                q.push(i);
            }
        }
    }
    return false;
}
bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    vector<int> adj[n];
    int size = edges.size();
    for(int i=0; i<size; i++){
        int f = edges[i][0];
        int s = edges[i][1];
        add(adj, f, s);
    }
    return path_exists(adj, source, destination, n);
}